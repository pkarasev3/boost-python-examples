#include <boost/python.hpp>
#include <iostream>
using namespace boost::python;

struct Position 
{ 
  float x, y, z; 
  Position() : x(0.0), y(0.0), z(0.0)                          { }
  Position(float x_, float y_, float z_) : x(x_), y(y_), z(z_) { }
  Position(const Position& rhs) : x(rhs.x), y(rhs.y), z(rhs.z) { }
};

struct Orientation { float x, y, z, w; };

struct Pose { Position pos; Orientation orient; };

template <int I, typename T> int value(const T&) { return I; }

BOOST_PYTHON_MODULE(m3b)
{
  class_<Position>("Position")
    .def(init<float, float, float>())
    .def_readwrite("x", &Position::x)
    .def_readwrite("y", &Position::y)
    .def_readwrite("z", &Position::z)
    .def("__len__", &value<3, Position>)
    ;

  class_<Orientation>("Orientation")
    .def_readwrite("x", &Orientation::x)
    .def_readwrite("y", &Orientation::y)
    .def_readwrite("z", &Orientation::z)
    .def_readwrite("w", &Orientation::w)
    .def("__len__", &value<4, Orientation>)
    ;

  class_<Pose>("Pose")
    .def_readwrite("pos", &Pose::pos)
    .def_readwrite("orient", &Pose::orient)
    ;
}

