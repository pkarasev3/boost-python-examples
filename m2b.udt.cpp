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


BOOST_PYTHON_MODULE(m2b)
{
  class_<MyClass>("MyClass")
    .def("hello_world", &MyClass::hello_world)
    ;
}
