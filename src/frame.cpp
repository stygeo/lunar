#include "lua_all.h"

#include "frame.h"
#include "script.h"
#include "script_engine.h"
#include "event_machine.h"

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
        // Call the lua callback
        try {
          (*itv)(this, event);
        } catch(luabind::error& e) {
          luabind::object error_message(luabind::from_stack(e.state(), -1));
          std::cout << "CallbackError: " << error_message << std::endl;
        }
      }
    }
  }
}

void Frame::onEvent(luabind::object cb)
{
  callbacks.push_back(cb);
}

void Frame::bind(lua_State *L)
{
  luabind::module(L)[
    luabind::class_<Frame, EventReceiver>("Frame")
      .def("onEvent", &Frame::onEvent)
  ];

  luabind::module(L) [
    luabind::def("CreateFrame", &CreateFrame)
  ];
}

Frame *CreateFrame(std::string name, std::string ext)
{
  lua_State *L = ScriptEngine::Get()->State();
  Frame *frame = new Frame(L);
  EventMachine::Get()->addReceiver(frame);
  std::cout << "("<< ext <<")" << ": '"<< name << "' created" << std::endl;

  return frame;
}

