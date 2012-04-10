#ifndef SCRIPT_H
#define SCRIPT_H

extern "C" {
  #include <lua.h>
  #include <lauxlib.h>
  #include <lualib.h>
}
#include <luabind/luabind.hpp>

class Script
{
  lua_State *L;
  public:
    Script();
    ~Script();

    void Run();

    lua_State *State() { return L; }
};

#endif
