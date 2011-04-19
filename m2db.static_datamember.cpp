#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

struct MyClass
{
  static float static_value;
};

float MyClass::static_value = 1.111;

BOOST_PYTHON_MODULE(m2db)
{
  object obj = class_<MyClass>("MyClass");

  obj.attr("static_value") = &MyClass::static_value;
}
