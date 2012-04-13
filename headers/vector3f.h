#ifndef VECTOR3F_H
#define VECTOR3F_H

#include "lua_all.h"

struct Vector3f
{
  Vector3f(float x, float y, float z) :
    x(x), y(y), z(z) {}

  float x,y,z;

  static void bind(lua_State *L);
};

Vector3f MakeVector3f(float x, float y, float z);

#endif
