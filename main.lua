print("Starting main.lua")

local frame = CreateFrame("PlayerHandler", "PlayerEx");
frame:registerEvent(PLAYER_ENTER);
frame:onEvent(function(self, event)

end);

local nodeFrame = CreateFrame("NodeCallback", "Node");
nodeFrame:registerEvent(NODE_CREATED);

local events = {};
function events:NODE_CREATED(self)
  print("Node created");
end

nodeFrame:onEvent(function(self, event)
  events[event](self);
end);

function main()
  local player = Node()
  player:setPosition(0, -2.4, -5)
  player:setColor(Colorf(1.0,1,1,.1))

  local enemy  = Node(0, 0, -11)
  enemy:setColor(Colorf(0.0,1,0,.1))

  local scene = engine:currentScene()
  scene:addChild(player)
  scene:addChild(enemy)

  while true do
    local pos = player:getPosition()
    local z = pos.z

    if z < -30 then
      z = -5
    else
      z = z + -0.5 * LU_DELTA;
    end
    pos.z = z

    player:setPosition(pos)
    yield();
  end
end

main()
