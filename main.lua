local mainSceneFrame = CreateFrame("MainScene", "Scene");
mainSceneFrame:registerEvent(INIT_MAIN_SCENE);
mainSceneFrame:registerEvent(RENDER_PASS);
local mainSceneEvents = {};

local player;
local enemy;
function mainSceneEvents:INIT_MAIN_SCENE(self)
  player = Node()
  player:setPosition(0, -2.4, -5)
  player:setColor(Colorf(1.0,1,1,.1))

  enemy  = Node(0, 0, -11)
  enemy:setColor(Colorf(0.0,1,0,.1))

  local scene = engine:currentScene()
  scene:addChild(player)
  scene:addChild(enemy)
end

function mainSceneEvents:RENDER_PASS(self)
  local pos = player:getPosition()
  local z = pos.z

  if z < -30 then
    z = -5
  else
    z = z + (-0.5 * LU_DELTA);
  end
  pos.z = z

  player:setPosition(pos)
end

mainSceneFrame:onEvent(function(self, event)
  mainSceneEvents[event](self);
end);
