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

  static void static_cling() 
  {
    std::cout << "I'm a static method\n";
  }

};


BOOST_PYTHON_MODULE(m2bb)
{
  class_<MyClass>("MyClass")
    .def("hello_world", &MyClass::hello_world)
    .def("static_cling", &MyClass::static_cling)
    .staticmethod("static_cling")
    ;
}
