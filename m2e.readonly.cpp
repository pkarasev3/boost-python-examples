#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

struct MyClass
{
  int value;

  void set_value(int j) { value = j; }
};

BOOST_PYTHON_MODULE(m2e)
{
  class_<MyClass>("MyClass")
    .def("set_value", &MyClass::set_value)
    .def_readonly("value", &MyClass::value)
    ;
}
