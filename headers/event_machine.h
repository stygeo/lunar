#pragma once


#include <vector>
#include <string>

#include "lua_all.h"
#include "event.h"

class EventMachine
{
  static EventMachine *singleton;

	std::vector<EventReceiver *> receivers;
	public:
		void addReceiver(EventReceiver *receiver);
		void fireEvent(std::string event);

    // Singleton methods
    static EventMachine *Get() {
      if(!singleton)
        singleton = new EventMachine();

      return singleton;
    }
};

