#pragma once

#include <string>

class Event
{
	int interval;
	void (*callback)(void*);
	std::string scriptCallback;

	public:
		Event(int interval, void (*cb)(void*));
		Event(int interval, std::string str);

		void call();

		int getInterval();
		void setInterval(int iv);

		void bind(lua_State *L);
};
