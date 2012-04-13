#include "lua_all.h"

#include "scene.h"

void Scene::draw()
{
  std::vector<Node*>::iterator it = childs.begin();
  for(;it != childs.end(); ++it)
  {
    (*it)->draw();
  }
}

void Scene::addChild(Node *node)
{
  childs.push_back(node);
}

void Scene::bind(lua_State *L)
{
  // Call bind on super first
  Node::bind(L);

  luabind::module(L)[
    luabind::class_<Scene>("Scene")
      .def("addChild", &Scene::addChild)
  ];
}
