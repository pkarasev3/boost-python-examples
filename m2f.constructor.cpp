#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

struct MyClass
{
  int value;

  void set_value(int j) { value = j; }

  MyClass(int v) : value(v) { }
};

BOOST_PYTHON_MODULE(m2f)
{
  class_<MyClass>("MyClass", init<int>())
    .def("set_value", &MyClass::set_value)
    .def_readonly("value", &MyClass::value)
    ;
}
