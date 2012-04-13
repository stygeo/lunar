#include "vector3f.h"

void Vector3f::bind(lua_State *L)
{
#ifdef DEBUG
  std::cout << "Binding Vector<T> to Lua" << std::endl;
#endif

  luabind::module(L) [
    luabind::class_<Vector3f>("Vector3f")
      .def(luabind::constructor<float, float, float>())
      .def_readwrite("x", &Vector3f::x)
      .def_readwrite("y", &Vector3f::y)
      .def_readwrite("z", &Vector3f::z)
  ];
}

Vector3f MakeVector3f(float x, float y, float z)
{
  return Vector3f(x, y, z);
}
