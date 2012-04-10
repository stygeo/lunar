#include "script.h"

extern "C" {
  #include <lua.h>
  #include <lauxlib.h>
  #include <lualib.h>
}
#include <luabind/luabind.hpp>

Script::Script()
{
  L = lua_open();
  luabind::open(L);
  luaL_openlibs(L);
}

Script::~Script()
{
  lua_close(L);
}

void Script::Run()
{
  if(luaL_dofile(L, "main.lua"))
  {
    std::cout << lua_tostring(L, -1) << std::endl;
  }
}
