#pragma once

extern "C" {
  #include <lua.h>
  #include <lauxlib.h>
  #include <lualib.h>
}
#include <luabind/luabind.hpp>
#include "event_machine.h"

class Script
{
  static Script *singleton;

  lua_State *L;
  lua_State *thread;
  bool running;

  public:
    Script();
    ~Script();

    bool dofile(std::string fileName);

    lua_State *State() { return thread; }
    int resume(float delta);
    static int yield(lua_State *S);

    static Script *Get() {
      if(!singleton)
        singleton = new Script();

      return singleton;
    }
};

