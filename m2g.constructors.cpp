#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

struct MyClass
{
  int value;

  void set_value(int j) { value = j; }

  MyClass(int v) : value(v) { }
  MyClass() : value(700) { }
};

BOOST_PYTHON_MODULE(m2g)
{
  class_<MyClass>("MyClass")
    .def(init<int>())
    .def("set_value", &MyClass::set_value)
    .def_readonly("value", &MyClass::value)
    ;
}
