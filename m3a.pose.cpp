#include <boost/python.hpp>
#include <iostream>
using namespace boost::python;

struct Position { float x, y, z; };

struct Orientation { float x, y, z, w; };

struct Pose { Position pos; Orientation orient; };

template <int I> int len() { return I; }

BOOST_PYTHON_MODULE(m3a)
{
  class_<Position>("Position")
    .def_readwrite("x", &Position::x)
    .def_readwrite("y", &Position::y)
    .def_readwrite("z", &Position::z)
    ;

  class_<Orientation>("Orientation")
    .def_readwrite("x", &Orientation::x)
    .def_readwrite("y", &Orientation::y)
    .def_readwrite("z", &Orientation::z)
    .def_readwrite("w", &Orientation::w)
    ;

  class_<Pose>("Pose")
    .def_readwrite("pos", &Pose::pos)
    .def_readwrite("orient", &Pose::orient)
    ;
}

