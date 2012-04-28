#include "lua_all.h"

#include "frame.h"
#include "script.h"
#include "event_machine.h"

void Frame::fireEvent(unsigned int event)
{
  std::vector<unsigned int>::iterator it = events.begin();
  for(;it != events.end(); ++it)
  {
    if((*it) == event)
    {
      std::vector<luabind::object>::iterator itv = callbacks.begin();
      for(;itv != callbacks.end(); ++itv)
      {
        // Call the lua callback
        (*itv)(this, event);
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
  lua_State *L = Script::Get()->State();
  Frame *frame = new Frame(L);
  EventMachine::Get()->addReceiver(frame);
  std::cout << "("<< ext <<")" << ": '"<< name << "' created" << std::endl;

  return frame;
}
