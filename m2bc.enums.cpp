#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

enum Lang { German, English, Spanish };

struct MyClass
{
  void hello_world(Lang l)
  {
    switch (l) {
    case English:
      std::cout << "Hello world\n";
      return;
    case Spanish:
      std::cout << "Hola mundo\n";
      return;
    case German:
      std::cout << "Hallo welt\n";
      return;
    }
  }
};


BOOST_PYTHON_MODULE(m2bc)
{
  enum_<Lang>("Lang")
    .value("German", German)
    .value("English", English)
    .value("Spanish", Spanish)
    .export_values()
    ;

  class_<MyClass>("MyClass")
    .def("hello_world", &MyClass::hello_world)
    ;
}
