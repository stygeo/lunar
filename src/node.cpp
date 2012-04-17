#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>

#include <iostream>
#include "lua_all.h"

#include "node.h"
#include "vector3f.h"

Node::Node() :
  position(MakeVector3f(.0,.0,.0)),
  color(Colorf(0,0,0,0))
{}

Node::Node(Vector3f position) :
  position(position),
  color(Colorf(0,0,0,0))
{}

Node::Node(float x, float y, float z) :
  position(MakeVector3f(x, y, z)),
  color(Colorf(0,0,0,0))
{}

void Node::draw()
{
  glPushMatrix();
  {
    glLoadIdentity();
    glTranslatef(position.x, position.y, position.z);
    glRotatef(20, 1.0, 0.0,0.0);
    glRotatef(40, 0.0, 1.0,0.0);

    //glutSolidSphere(0.20f, 120, 120);
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_QUADS);          // Start Drawing Quads
        // Front Face
        glNormal3f( 0.0f, 0.0f, 1.0f);      // Normal Facing Forward
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
        // Back Face
        glNormal3f( 0.0f, 0.0f,-1.0f);      // Normal Facing Away
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
        // Top Face
        glNormal3f( 0.0f, 1.0f, 0.0f);      // Normal Facing Up
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
        // Bottom Face
        glNormal3f( 0.0f,-1.0f, 0.0f);      // Normal Facing Down
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        // Right face
        glNormal3f( 1.0f, 0.0f, 0.0f);      // Normal Facing Right
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        // Left Face
        glNormal3f(-1.0f, 0.0f, 0.0f);      // Normal Facing Left
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
    glEnd();                    // Done Drawing Quads

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

void Node::setPosition(float x, float y, float z)
{
  position = MakeVector3f(x,y,z);
}

Vector3f Node::getPosition()
{
  return position;
}

void Node::setColor(Colorf p_color)
{
  color = p_color;
}

Colorf Node::getColor()
{
  return color;
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
      .def("setPosition", (void(Node::*)(Vector3f)) &Node::setPosition)
      .def("setPosition", (void(Node::*)(float,float,float)) &Node::setPosition)
      .def("setColor", &Node::setColor)
      .def("getColor", &Node::getColor),

    luabind::def("MakeVector3f", MakeVector3f)
  ];
}
