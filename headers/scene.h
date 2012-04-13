#ifndef SCENE_H
#define SCENE_H

#include "node.h"

class Scene
{
  private:
    std::vector<Node*> childs;
  public:
    void draw();
    void addChild(Node *node);
    static void bind(lua_State *L);
};

#endif
