#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_Opengl.h>

#include "window.h"
#include "renderer.h"
#include "script.h"
#include "model.h"

const int RUN_GAME_LOOP = 1;

class Engine
{
  Window *window;
  Renderer *renderer;
  Script *script;

  std::vector<SDL_TimerID> timers;
  bool done;

  public:
    Engine();
    void EventLoop();
    void HandleEvents(SDL_Event *event);
    void GameLoop();
    void AddModel(Model *model);

    static Uint32 GameLoopTimer(Uint32 interval, void *param);
};

#endif
