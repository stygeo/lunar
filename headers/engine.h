#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_Opengl.h>

#include "window.h"
#include "renderer.h"
#include "scene.h"

const int RUN_GAME_LOOP = 1;

class Engine
{
  unsigned int ltime;

  Window *window;
  Renderer *renderer;
  Scene *currentScene;
  std::vector<Scene*> scenes;

  std::vector<SDL_TimerID> timers;
  bool done;

  public:
    Engine();
    void EventLoop();
    void HandleEvents(SDL_Event *event);
    void GameLoop(float delta);
    void runWithScene(Scene *scene);

    static Uint32 GameLoopTimer(Uint32 interval, void *param);

    // Setters and getters
    Scene *getCurrentScene();

  protected:
    void bind();
};

#endif
