#include <boost/python.hpp>
#include <boost/format.hpp>
#include <iostream>
using namespace boost::python;

#include "Position.h"

namespace 
{
  tuple to_tuple(const Position& p)
  {
    return make_tuple(p.x, p.y, p.z);
  }

  std::string repr(const Position& p) 
  {
    return boost::str(boost::format("Position(%f,%f,%f)") % p.x % p.y % p.z);
  }
}

BOOST_PYTHON_MODULE(m3f)
{
  class_<Position>("Position")
    .def(init<float, float, float>())
    .def_readwrite("x", &Position::x)
    .def_readwrite("y", &Position::y)
    .def_readwrite("z", &Position::z)
    .def("to_tuple", &to_tuple)
    .def("__repr__", &repr)
    ;
}
