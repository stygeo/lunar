#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_OpenGL.h>

#include "engine.h"
#include "window.h"
#include "renderer.h"
#include "model.h"
#include "script.h"

Engine::Engine()
{
  window = new Window(600, 600);
  renderer = new Renderer(window);
  script = new Script();
  done = false;

  timers.push_back(SDL_AddTimer(20, GameLoopTimer, this));

  lua_State* L = script->State();
  luabind::module(L)[
    luabind::class_<Model>("Model")
      .def(luabind::constructor<>())
      .def("Draw", &Model::Draw)
  ];
  luabind::module(L)[
    luabind::class_<Engine>("Engine")
      .def("AddModel", &Engine::AddModel)
  ];

  luabind::globals(L)["engine"] = this;

  script->Run();
}

void Engine::AddModel(Model *model)
{
  std::cout << "Received object: " << model << std::endl;
}

void Engine::EventLoop()
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

void Engine::HandleEvents(SDL_Event *event)
{
  switch(event->user.code) {
    case RUN_GAME_LOOP:
      GameLoop();
      break;
    default:
      break;
  }
}

void Engine::GameLoop()
{
  renderer->Before();
  {

  }
  renderer->After();

  window->Swap();
}

Uint32 Engine::GameLoopTimer(Uint32 interval, void *param)
{
  SDL_Event event;

  event.type = SDL_USEREVENT;
  event.user.code = RUN_GAME_LOOP;
  event.user.data1 = 0;
  event.user.data2 = 0;

  SDL_PushEvent(&event);

  return interval;
}
