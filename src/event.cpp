#include "event.h"

void EventReceiver::registerEvent(std::string event)
{
	events.push_back(event);
}

void EventReceiver::bind(lua_State *L)
{
  luabind::globals(L)["PLAYER_ENTER"] = PLAYER_ENTER;
  luabind::globals(L)["NODE_CREATED"] = NODE_CREATED;
  luabind::globals(L)["INIT_MAIN_SCENE"] = INIT_MAIN_SCENE;
  luabind::globals(L)["RENDER_PASS"] = RENDER_PASS;

  luabind::module(L)[
    luabind::class_<EventReceiver>("EventReceiver")
      .def("registerEvent", &EventReceiver::registerEvent)
  ];


}
