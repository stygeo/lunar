-- Create a new frame for the main scene initialized in "C: `main`"
local mainSceneFrame = CreateFrame("MainScene", "Scene");
-- Register to INIT_MAIN_SCENE event.
mainSceneFrame:registerEvent(INIT_MAIN_SCENE);
-- Register to RENDER_PASS event. Used to update the 'scene'.
mainSceneFrame:registerEvent(RENDER_PASS);
-- Create a events table.
local mainSceneEvents = {};

local player;
local enemy;

-- INIT_MAIN_SCENE event callback
function mainSceneEvents:INIT_MAIN_SCENE(obj)
  print("Called init main screen from " .. obj:getName());
  player = Node()
  player:setPosition(0, -2.4, -5)
  player:setColor(Colorf(1.0,1,1,.1))

  enemy  = Node(0, 0, -11)
  enemy:setColor(Colorf(0.0,1,0,.1))

  local scene = engine:currentScene()
  scene:addChild(player)
  scene:addChild(enemy)
end

-- RENDER_PASS event callback
function mainSceneEvents:RENDER_PASS(obj)
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

-- Main event 'catcher'. Calls the proper callback to which the frame is registered to.
mainSceneFrame:onEvent(function(self, event)
  if event == INIT_MAIN_SCENE then
    mainSceneEvents:INIT_MAIN_SCENE(self);
  elseif event == RENDER_PASS then
    mainSceneEvents:RENDER_PASS(self);
  end
end);

