#pragma once

#include <string>
#include <vector>
#include "lua_all.h"

const unsigned int PLAYER_ENTER = 0;
const unsigned int NODE_CREATED = 1;

struct EventReceiver
{
	virtual void onEvent(luabind::object cb) = 0;
	virtual void afterEvent(unsigned int event) = 0;
	virtual void fireEvent(unsigned int event) = 0;
	void registerEvent(unsigned int event);
  static void bind(lua_State *L);

	protected:
		std::vector<unsigned int> events;
		std::vector<luabind::object> callbacks;
};

