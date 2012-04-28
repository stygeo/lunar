#include "engine.h"
#include "scene.h"

class TestScene : public Scene{};

int main(int argc, char *argv[])
{
  Engine *engine = new Engine();
	TestScene *scene = new TestScene();
	engine->runWithScene(scene);

  return 0;
}
