#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_OpenGL.h>

#include "engine.h"
#include "window.h"
#include "renderer.h"
#include "script.h"
#include "vector3f.h"

Engine::Engine()
{
  window = new Window(600, 600);
  renderer = new Renderer(window);
  script = new Script();
  done = false;

  timers.push_back(SDL_AddTimer(20, GameLoopTimer, this));

  // Bind objects to Lua
  bind();
}

void Engine::runWithScene(Scene *scene)
{
  currentScene = scene;
  scenes.push_back(scene);

  script->Run();
  // Enter the event loop
  EventLoop();
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

  currentScene->draw();

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

void Engine::bind()
{
  lua_State* L = script->State();

  Vector3f::bind(L);
  Scene::bind(L);

  luabind::module(L)[
    luabind::class_<Engine>("Engine")
      .def("currentScene", &Engine::getCurrentScene)
      .def("print", &Engine::print)
  ];

  luabind::globals(L)["engine"] = this;
}

int Engine::print()
{
  return 1000;
}

// Setters and getters
#pragma mark "Setters and gettings"
Scene *Engine::getCurrentScene()
{
  return currentScene;
}
