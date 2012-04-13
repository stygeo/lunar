#ifndef OBJECT_H
#define OBJECT_H

#include "lua_all.h"

class Object
{
  public:
    virtual void bind(lua_State *L) = 0;
};

#endif
