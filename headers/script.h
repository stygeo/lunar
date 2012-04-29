#pragma once
#include <string>

extern "C" {
  #include <lua.h>
  #include <lauxlib.h>
  #include <lualib.h>
}
#include <luabind/luabind.hpp>
#include "event_machine.h"

class Script
{
  int luaState;

  lua_State *L;

  public:
    Script(lua_State *L, std::string file);

    void doScript();
};

