#pragma once

#include <string>
#include <vector>
#include <boost/ref.hpp>
#include "lua_all.h"

const std::string PLAYER_ENTER("PLAYER_ENTER");
const std::string NODE_CREATED("NODE_CREATED");
const std::string INIT_MAIN_SCENE("INIT_MAIN_SCENE");
const std::string RENDER_PASS("RENDER_PASS");

struct EventReceiver
{
  // TODO
  // MainScene -> Creates an object (currently in lua), called player
  // Fire PLAYER_ENTER. Manage player through lua. 
  // Frame <-> Observer
  // Observer<type T> (Node?) interaction between observers and nodes.
  // frame:hook("OnEvent", function(self, event) ... end);
  // frame:hook("OnKeyDown", function(self, key) ... end);
  // frame:hook("OnClick", function(self, mouse, object) ... end);
  //virtual void hook(std::string type, luabind::object cb) = 0;
  // { "OnEvent": std::vector<luabind::object>,
  //   "OnClick": ^^^^^^^^^^^^^^^^^^^^^^^^^^^^,
  //   "OnKeyDown: ^^^^^^^^^^^^^^^^^^^^^^^^^^^,
  // }
	virtual void onEvent(luabind::object cb) = 0;
	virtual void afterEvent(unsigned int event) = 0;
	virtual void fireEvent(std::string event) = 0;
	void registerEvent(std::string event);
  static void bind(lua_State *L);

	protected:
		std::vector<std::string> events;
		std::vector<luabind::object> callbacks;
};

