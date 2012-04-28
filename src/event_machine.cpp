#include "event_machine.h"

EventMachine *EventMachine::singleton = 0;

void EventMachine::addReceiver(EventReceiver *receiver)
{
	receivers.push_back(receiver);
}

void EventMachine::fireEvent(unsigned int event)
{
  std::vector<EventReceiver *>::iterator it = receivers.begin();
  for(;it != receivers.end(); ++it)
  {
		(*it)->fireEvent(event);
  }
}

