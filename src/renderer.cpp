#include <SDL/SDL.h>
#include <SDL/SDL_OpenGL.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include <iostream>

#include "renderer.h"

Renderer::Renderer(Window *window) :
  window(window)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //gluPerspective(45, window->GetWidth() / window->GetHeight(), 1, 1000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glEnable(GL_CULL_FACE);
  //glEnable(GL_DEPTH_TEST);
  gluOrtho2D(0.0, 4.0, 0.0, 3.0);

  glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Renderer::Before()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  glLoadIdentity();
}

void Renderer::After()
{
  glPopMatrix();
}
