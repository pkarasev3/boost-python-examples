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

struct Unwrapped { };

Unwrapped make_unwrapped()
{
  Unwrapped u;
  return u;
}

void use_myclass(MyClass m, int j)
{
  m.hello_world(j+2);
}


BOOST_PYTHON_MODULE(m2cb)
{
  class_<MyClass>("MyClass")
    .def("hello_world", &MyClass::hello_world)
    ;

  def("use_myclass", &use_myclass);
  def("make_unwrapped", &make_unwrapped);

}
