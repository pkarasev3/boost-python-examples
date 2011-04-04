#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

struct MyClass
{
  int value;

  void hello_world(int j)
  {
    std::cout << "(" << j << " times)\n";
    for (int i=0; i<j; ++i)
      std::cout << "hi!\n";
  }
};

void use_myclass(MyClass m)
{
  m.hello_world(m.value);
}


BOOST_PYTHON_MODULE(m2d)
{
  class_<MyClass>("MyClass")
    .def("hello_world", &MyClass::hello_world)
    .def_readwrite("value", &MyClass::value)
    ;

  def("use_myclass", &use_myclass)
    ;

}
