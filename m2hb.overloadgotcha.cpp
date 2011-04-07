#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

struct MyClass
{
  bool twice(bool b)
  {
    std::cout << "twice(bool)\n";
    return b;
  }

  int twice(int i) 
  {
    std::cout << "twice(int)\n";
    return i + i;
  }
};

BOOST_PYTHON_MODULE(m2hb)
{
  class_<MyClass>("MyClass")
    .def("twice", (bool(MyClass::*)(bool)) &MyClass::twice)
    .def("twice", (int (MyClass::*)(int))  &MyClass::twice)
    ;
}
