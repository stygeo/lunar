#pragma once

#include "event.h"
#include "lua_all.h"

class Frame : public EventReceiver
{
  lua_State *L;

  public:
    Frame(lua_State *L) : L(L) {};
    void onEvent(luabind::object cb);
    void fireEvent(unsigned int event);
    void afterEvent(unsigned int event) {};

    static void bind(lua_State *L);
};

Frame *CreateFrame(std::string name, std::string ext);
