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

struct Colorf
{
  Colorf(float r, float g, float b, float a) :
    r(r), g(g), b(b), a(a) {}

  float r,g,b,a;

  static void bind(lua_State *L);
};

Vector3f MakeVector3f(float x, float y, float z);

#endif
