#include "script.h"

extern "C" {
  #include <lua.h>
  #include <lauxlib.h>
  #include <lualib.h>
}
#include <luabind/luabind.hpp>

Script::Script(lua_State *R, std::string file)
{
  L = R;
  luaState = luaL_loadfile(L, file.c_str());
  if(luaState) {
    // Pop error message of the stack
    std::cout << lua_tostring(L, -1) << std::endl;
  }
}

void Script::doScript()
{
  // Duplicate top stack so we are able to re-run the script
  lua_pushvalue(L, -1);
  lua_pcall(L, 0, LUA_MULTRET, 0);
}

