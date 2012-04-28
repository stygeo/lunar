#include <iostream>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_OpenGL.h>

#include "config.h"
#include "engine.h"
#include "window.h"
#include "renderer.h"
#include "script.h"
#include "vector3f.h"
#include "event_machine.h"
#include "event.h"
#include "frame.h"


Engine::Engine()
{
  std::cout << "Initializing Lunar " << LU_VERSION << std::endl;

  window = new Window(600, 600);
  renderer = new Renderer(window);
  script = Script::Get();
  done = false;

  timers.push_back(SDL_AddTimer(20, Engine::GameLoopTimer, this));

  // Bind objects to Lua
  bind();

  ltime = SDL_GetTicks();
}

void Engine::runWithScene(Scene *scene)
{
  currentScene = scene;
  scenes.push_back(scene);

  script->dofile("main.lua");
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
  unsigned int ctime = SDL_GetTicks();
  float delta = (float)(ctime - ltime)/100.0f;
  ltime = ctime;
  luabind::globals(script->State())["LU_DELTA"] = delta;

  switch(event->user.code) {
    case RUN_GAME_LOOP:
      GameLoop(delta);
      break;
    default:
      break;
  }
}

void Engine::GameLoop(float delta)
{
  renderer->Before();
  EventMachine::Get()->fireEvent(PLAYER_ENTER);

  script->resume(delta);
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

  Colorf::bind(L);
  EventReceiver::bind(L);
  Vector3f::bind(L);
  Scene::bind(L);
  Frame::bind(L);

  luabind::module(L)[
    luabind::class_<Engine>("Engine")
      .def("currentScene", &Engine::getCurrentScene)
  ];

  luabind::globals(L)["engine"] = this;
}

// Setters and getters
#pragma mark "Setters and gettings"
Scene *Engine::getCurrentScene()
{
  return currentScene;
}
