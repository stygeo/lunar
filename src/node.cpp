#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>

#include <iostream>
#include "lua_all.h"

#include "node.h"
#include "vector3f.h"

Node::Node() :
  position(MakeVector3f(.0,.0,.0)) {}

Node::Node(Vector3f position) :
  position(position) {}

Node::Node(float x, float y, float z) :
  position(MakeVector3f(x, y, z)) {}

void Node::draw()
{
  glPushMatrix();
  {
    glLoadIdentity();
    glTranslatef(position.x, position.y, position.z);
    glutSolidSphere(0.20f, 120, 120);

    std::vector<Node*>::iterator it = childs.begin();
    for(;it != childs.end(); ++it)
    {
      (*it)->draw();
    }
  } glPopMatrix();
}

void Node::addChild(Node *node)
{
  childs.push_back(node);
}

void Node::setPosition(Vector3f pos)
{
  position = pos;
}

Vector3f Node::getPosition()
{
  return position;
}

void Node::bind(lua_State *L)
{
  std::cout << "Binding Node to Lua" << std::endl;

  luabind::module(L) [
    luabind::class_<Node>("Node")
      .def(luabind::constructor<>())
      .def(luabind::constructor<Vector3f>())
      .def(luabind::constructor<float, float, float>())
      .def("draw", &Node::draw)
      .def("addChild", &Node::addChild)
      .def("getPosition", &Node::getPosition)
      .def("setPosition", &Node::setPosition),

    luabind::def("MakeVector3f", MakeVector3f)
  ];
}
