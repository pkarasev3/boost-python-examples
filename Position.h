#pragma once

struct Position 
{ 
  float x, y, z; 
  Position() : x(0.0), y(0.0), z(0.0)                          { }
  Position(float x_, float y_, float z_) : x(x_), y(y_), z(z_) { }
  Position(const Position& rhs) : x(rhs.x), y(rhs.y), z(rhs.z) { }
};

