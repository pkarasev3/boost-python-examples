#include <boost/python.hpp>

std::string handle_pyerror()
{
    using namespace boost::python;

    std::ostringstream os;
    os << "Python error:\n  " << std::flush;

    PyObject *type = 0, *val = 0, *tb = 0;
    PyErr_Fetch(&type, &val, &tb);
    handle<> e_val(val), e_type(type), e_tb(allow_null(tb));

    try {
        object t = extract<object>(e_type.get());
        object t_name = t.attr("__name__");
        std::string typestr = extract<std::string>(t_name);

        os << typestr << std::flush;
    } catch (error_already_set const &) {
        os << "Internal error getting error type:\n";
        PyErr_Print();
    }

    os << ": ";

    try {
        object v = extract<object>(e_val.get());
        std::string valuestr = extract<std::string>(v.attr("__str__")());
        os  << valuestr << std::flush;
    } catch (error_already_set const &) {
        os << "Internal error getting value type:\n";
        PyErr_Print();
    }

    if (tb) {
        try {
            object tb_list = import("traceback").attr("format_tb")(e_tb);
            object tb_str = str("").attr("join")(tb_list);
            std::string str = extract<std::string>(tb_str);

            os << "\nTraceback (recent call last):\n" << str;
        } catch (error_already_set const &) {
            os << "Internal error getting traceback:\n";
            PyErr_Print();
        }
    } else {
        os << std::endl;
    }

    return os.str();
}
