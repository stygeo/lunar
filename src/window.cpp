#include "window.h"

#include <SDL/SDL.h>
#include <SDL/SDL_OpenGL.h>

Window::Window(int width, int height, bool fullscreen) :
  m_width(width), m_height(height)
{
  int errors = SDL_Init(SDL_INIT_EVERYTHING);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
  SDL_Surface *ctx;

  Uint32 flags;

  if(fullscreen)
    flags = SDL_OPENGL | SDL_FULLSCREEN;
  else
    flags = SDL_OPENGL;

  ctx = SDL_SetVideoMode(width, height, 0, flags);
}

void Window::Swap()
{
  SDL_GL_SwapBuffers();
}
