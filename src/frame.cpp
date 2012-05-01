#include "lua_all.h"

#include "frame.h"
#include "script.h"
#include "script_engine.h"
#include "event_machine.h"
#include <boost/ref.hpp>

Frame::Frame(lua_State *L, std::string name, std::string description) :
  L(L), name(name), description(description)
{}

void Frame::fireEvent(std::string event)
{
  std::vector<std::string>::iterator it = events.begin();
  for(;it != events.end(); ++it)
  {
    if((*it) == event)
    {
      std::vector<luabind::object>::iterator itv = callbacks.begin();
      for(;itv != callbacks.end(); ++itv)
      {
        try
        {
          // Call the lua callback
          luabind::call_function<void>((*itv), this, event);
        }
        catch(luabind::error& e)
        {
          luabind::object error_message(luabind::from_stack(e.state(), -1));
          std::cout << error_message << std::endl;
        }
      }
    }
  }
}

void Frame::onEvent(luabind::object cb)
{
  callbacks.push_back(cb);
}

std::string Frame::getName() { return name; }
std::string Frame::getDescription() { return description; }

void Frame::bind(lua_State *L)
{
  luabind::module(L)[
    luabind::class_<Frame, EventReceiver>("Frame")
      .def("onEvent", &Frame::onEvent)
      .def("getName", &Frame::getName)
      .def("getDescription", &Frame::getDescription)
  ];

  luabind::module(L) [
    luabind::def("CreateFrame", &CreateFrame)
  ];
}

Frame *CreateFrame(std::string name, std::string ext)
{
  lua_State *L = ScriptEngine::Get()->State();
  Frame *frame = new Frame(L, name, ext);
  EventMachine::Get()->addReceiver(frame);
  std::cout << "("<< ext <<")" << ": '"<< name << "' created" << std::endl;

  return frame;
}

