#include <boost/python.hpp>
#include <iostream>

namespace bp = boost::python;

std::string handle_pyerror();

int main(int argc, char** argv)
{
  try {
    char* configfile_name = argv[1];
  
    Py_Initialize();
    bp::object main = bp::import("__main__");
    bp::object py_ = main.attr("__dict__");
    bp::exec_file(argv[1], py_, py_);

    int niter = bp::extract<int>(py_["niter"]);
    std::cout << "niter = " << niter << "\n";
  } catch(const bp::error_already_set& e) {
    std::cerr << handle_pyerror();
  }
  
}
