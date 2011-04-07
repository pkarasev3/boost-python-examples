#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

void throws_runtime_error() {
  throw std::runtime_error("[[[ thrown runtime error ]]]");
}

void throws_logic_error() {
  throw std::logic_error("[[[ thrown logic error ]]]");
}

BOOST_PYTHON_MODULE(m2ga)
{
  def("throws_runtime_error", &throws_runtime_error);
  def("throws_logic_error", &throws_logic_error);
}
