#include "lua_all.h"

#include "event.h"

#include <vector>
#include <string>
#include <SDL/SDL.h>

Event::Event(int interval, void (*cb)(void*)) :
	interval(interval), callback(cb), scriptCallback("")
{}

Event::Event(int interval, std::string str) :
	interval(interval), scriptCallback(str), callback(NULL)
{};

void Event::call()
{
	if(callback != NULL)
	{
		callback(this);
	}
	else
	{
		// TODO
	}
}

int Event::getInterval() { return interval; }
// TODO Reschedule with new interval
void Event::setInterval(int iv) { interval = interval; }

void Event::bind(lua_State *L)
{
	luabind::module(L)
	[
		luabind::class_<Event>("Event")
			.def(luabind::constructor<int, std::string>())
			.def("getInterval", &Event::getInterval)
			.def("setInterval", &Event::setInterval)
	];
}

