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
  std::string repr(const Position& p) 
  {
    return boost::str(boost::format("Position(%f,%f,%f)") % p.x % p.y % p.z);
  }

  float getitem(const Position& p, int i)
  {
    switch (i) {
    case 0: return p.x;
    case 1: return p.y;
    case 2: return p.z;
    default:
      PyErr_SetString(PyExc_IndexError, "Position index out of range");
      throw error_already_set();
    }
  }

  void setitem(Position& p, int i, float f)
  {
    switch (i) {
    case 0: p.x = f; return;
    case 1: p.y = f; return;
    case 2: p.z = f; return;
    default:
      PyErr_SetString(PyExc_IndexError, "Position index out of range");
      throw error_already_set();
    }
  }
}

BOOST_PYTHON_MODULE(m3e)
{
  class_<Position>("Position")
    .def(init<float, float, float>())
    .def_readwrite("x", &Position::x)
    .def_readwrite("y", &Position::y)
    .def_readwrite("z", &Position::z)
    .def("__len__", &value<3, Position>)
    .def("__repr__", &repr)
    .def("__getitem__", (float (*)(const Position&, int i))   &getitem)
    .def("__setitem__", (void (*)(Position&, int i, float f)) &setitem)
    ;
}
