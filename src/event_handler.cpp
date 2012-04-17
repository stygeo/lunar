#include "event_handler.h"

void EventHandler::eventLoop()
{
  SDL_Event event;
  while(!done && SDL_WaitEvent(&event))
  {
    switch(event.type) {
      case SDL_USEREVENT:
        HandleEvents(&event);
        break;
      case SDL_QUIT:
        done = true;
        break;
    }
  }
}

void EventHandler::handleEvents()
{
  switch(event->user.code) {
    case RUN_GAME_LOOP:
      GameLoop();
      break;
    default:
      break;
  }
}

void EventHandler::addEvent(Event *event)
{
	events.push_back(event);
}
