#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

struct MyClass
{
  std::string twice(std::string s)
  {
    return s + s;
  }

  int twice(int i) 
  {
    return i + i;
  }
};

BOOST_PYTHON_MODULE(m2ha)
{
  class_<MyClass>("MyClass")
    .def("twice", (std::string(MyClass::*)(std::string)) &MyClass::twice)
    .def("twice", (int (MyClass::*)(int))                &MyClass::twice)
    ;
}
