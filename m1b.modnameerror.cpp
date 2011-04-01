#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

void hello_world()
{
  std::cout << "hi!\n";
}

BOOST_PYTHON_MODULE(wrongname)
{
  def("hello_world", &hello_world);
}
