#ifndef NODE_H
#define NODE_H

#include <vector>
#include "vector3f.h"

class Node
{
  protected:
    std::vector<Node*> childs;
    Vector3f position;
    Colorf color;

  public:
    Node();
    Node(Vector3f position);
    Node(float x, float y, float z);

    void draw();
    void addChild(Node *node);

    void setPosition(Vector3f pos);
    void setPosition(float x, float y, float z);
    Vector3f getPosition();

    void setColor(Colorf color);
    Colorf getColor();

    static void bind(lua_State *L);
};

#endif
