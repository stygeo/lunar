#include "event.h"

void EventReceiver::registerEvent(unsigned int event)
{
	events.push_back(event);
}

void EventReceiver::bind(lua_State *L)
{
  luabind::globals(L)["PLAYER_ENTER"] = PLAYER_ENTER;
  luabind::globals(L)["NODE_CREATED"] = NODE_CREATED;

  luabind::module(L)[
    luabind::class_<EventReceiver>("EventReceiver")
      .def("registerEvent", &EventReceiver::registerEvent)
  ];


}
