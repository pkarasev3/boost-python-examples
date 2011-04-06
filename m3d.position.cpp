#include <boost/python.hpp>
#include <boost/format.hpp>
#include <iostream>
using namespace boost::python;

struct Position 
{ 
  float x, y, z; 
  Position() : x(0.0), y(0.0), z(0.0)                          { }
  Position(float x_, float y_, float z_) : x(x_), y(y_), z(z_) { }
  Position(const Position& rhs) : x(rhs.x), y(rhs.y), z(rhs.z) { }
};

template <int I, typename T> int value(const T&) { return I; }

namespace 
{
  int hash(const Position& p) 
  {
    return *reinterpret_cast<const int*>(&p.x) ^
      *reinterpret_cast<const int*>(&p.y) ^
      *reinterpret_cast<const int*>(&p.z); 
  }
  std::string repr(const Position& p) 
  {
    return boost::str(boost::format("Position(%f,%f,%f)") % p.x % p.y % p.z);
  }
}

BOOST_PYTHON_MODULE(m3c)
{
  class_<Position>("Position")
    .def(init<float, float, float>())
    .def_readwrite("x", &Position::x)
    .def_readwrite("y", &Position::y)
    .def_readwrite("z", &Position::z)
    .def("__len__", &value<3, Position>)
    .def("__hash__", &hash)
    .def("__repr__", &repr)
    ;
}

