#pragma once

#include "event.h"
#include "lua_all.h"

class Frame : public EventReceiver
{
  lua_State *L;
  std::string name;
  std::string description;

  public:
    static void bind(lua_State *L);

    Frame(lua_State *L, std::string name, std::string description);
    void onEvent(luabind::object cb);
    void fireEvent(std::string event);
    void afterEvent(unsigned int event) {};

    std::string getName();
    std::string getDescription();
};

Frame *CreateFrame(std::string name, std::string ext);
