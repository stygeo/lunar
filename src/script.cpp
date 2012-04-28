#include "script.h"

extern "C" {
  #include <lua.h>
  #include <lauxlib.h>
  #include <lualib.h>
}
#include <luabind/luabind.hpp>

Script *Script::singleton = 0;

Script::Script()
{
  L = lua_open();

  luabind::open(L);
  luaL_openlibs(L);
  lua_register(L, "yield", yield);
  lua_register(L, "LU_WaitEvent", yield);

  // Setting up a thread for lua
  thread = lua_newthread(L);
  //lua_newtable(thread);
  //lua_newtable(thread);
  //lua_pushliteral(thread, "__index");
  //lua_pushvalue(thread, LUA_GLOBALSINDEX);
  //lua_settable(thread, -3);
  //lua_setmetatable(thread, -2);
  //lua_replace(thread, LUA_GLOBALSINDEX);

  std::cout << "Initialized " << LUA_VERSION << std::endl;
}

Script::~Script()
{
  lua_close(L);
}

int Script::yield(lua_State *L)
{
  return lua_yield(L, 1);
}

int Script::resume(float delta)
{
  if(!running) return -1;

  int status;
  if(lua_isstring(thread, -1)) {
    std::cout << "Error in script: " << lua_tostring(thread, -1);
  }

  status = lua_resume(thread, 0);
  if(status == LUA_YIELD) {
    // Handle yielding
  } else {
    running = false;
    if(status == LUA_ERRRUN && lua_isstring(thread, -1)) {
      std::cout << "Uncaught Exception:\n" << lua_tostring(thread, -1) << std::endl;
      lua_pop(thread, -1);
    }
  }

  return status;
}

bool Script::dofile(std::string fileName)
{
  running = true;
  if(luaL_loadfile(thread, fileName.c_str()))
  {
    std::cout << lua_tostring(thread, -1) << std::endl;

    return false;
  }

  return true;
}

