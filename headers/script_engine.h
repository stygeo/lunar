#pragma once

extern "C" {
  #include <lua.h>
  #include <lauxlib.h>
  #include <lualib.h>
}
#include <luabind/luabind.hpp>
#include "script.h"

class ScriptEngine
{
  static ScriptEngine *singleton;

  lua_State *L;

  public:
    static ScriptEngine *Get();

    ScriptEngine();

    lua_State *State();

    // Run a file. Does not support coroutines/yields
    Script *dofile(std::string file);
    // Create a new Script object. Run at a given time.
    Script *CreateScript(std::string file);

};

