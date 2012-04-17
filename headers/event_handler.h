#pragma once

#include <SDL/SDL.h>
#include <vector>
#include <event.h>

class EventHandler
{
	std::vector<Event*> events;
	public:
		void eventLoop();
		void handleEvents();
		void addEvent(Event *event);
};
