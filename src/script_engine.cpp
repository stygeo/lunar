#include "script_engine.h"

ScriptEngine *ScriptEngine::singleton = 0;

ScriptEngine *ScriptEngine::Get()
{
  if(!singleton)
  {
    singleton = new ScriptEngine();
  }

  return singleton;
}

ScriptEngine::ScriptEngine()
{
  L = lua_open();

  luabind::open(L);
  luaL_openlibs(L);

  std::cout << "Initialized " << LUA_VERSION << std::endl;
}

Script *ScriptEngine::dofile(std::string file)
{
  Script *script = CreateScript(file);
  // Run the script
  script->doScript();

  return script;
}

Script *ScriptEngine::CreateScript(std::string file)
{
  lua_State *thread = lua_newthread(L);
  Script *script = new Script(thread, file);

  return script;
}

lua_State *ScriptEngine::State()
{
  return L;
}

