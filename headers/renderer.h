#ifndef RENDERER_H
#define RENDERER_H

#include "window.h"

class Renderer
{
  Window *window;

  public:
    Renderer(Window *window);

    void Before();
    void After();
};

#endif
