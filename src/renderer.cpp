#include <SDL/SDL.h>
#include <SDL/SDL_OpenGL.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include <iostream>

#include "renderer.h"

Renderer::Renderer(Window *window) :
  window(window)
{
  glShadeModel(GL_SMOOTH);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, window->GetWidth() / window->GetHeight(), .1, 1000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);

  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_POLYGON_SMOOTH);
  glEnable(GL_MULTISAMPLE_ARB);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

  glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
  glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

  GLfloat ambient[] = {.2f, .2f, .2f, 1.0f};
  GLfloat diffuseLight[] = {0.8f, 0.8f, 0.8f, 1.0f};
  GLfloat specularLight[] = {0.5f, 0.5f, 0.5f, 1.0f};
  GLfloat position[] = {.0f, .0f, .0f, 1.0f};
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
  glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
  glLightfv(GL_LIGHT0, GL_POSITION, position);

  glEnable(GL_LIGHTING);
  //glEnable(GL_LIGHT0);

  glCullFace(GL_BACK);
  glEnable(GL_CULL_FACE);

  glEnable(GL_POLYGON_SMOOTH);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_ONE);
  glHint(GL_POLYGON_SMOOTH_HINT, GL_DONT_CARE);

  glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Renderer::Before()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
  glPushMatrix();
  glLoadIdentity();
}

void Renderer::After()
{
  glPopMatrix();
}
