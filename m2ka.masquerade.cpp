#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

struct MyClass
{
  void hello_world(int j)
  {
    std::cout << "(" << j << " times)\n";
    for (int i=0; i<j; ++i)
      std::cout << "hi!\n";
  }
};

void hello_times2(MyClass& mc, int value)
{
  mc.hello_world(value*2);
}


BOOST_PYTHON_MODULE(m2ka)
{
  class_<MyClass>("MyClass")
    .def("hello_world", &MyClass::hello_world)
    .def("hello_times2", &hello_times2)
    ;
}
