#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

struct MyClass
{
  void set_value(int j) { 
    std::cout << "setting to " << j << "\n";
    value = j; 
  }
  int get_value() { 
    std::cout << "getting!\n";
    return value; 
  }

  MyClass(int v) : value(v) { }
  MyClass() : value(700) { }

private:
  int value;
};

BOOST_PYTHON_MODULE(m2h)
{
  class_<MyClass>("MyClass")
    .def(init<int>())
    .add_property("value",   &MyClass::get_value, &MyClass::set_value)
    .add_property("rovalue", &MyClass::get_value)
    ;
}
