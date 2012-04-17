print("Hello world")

print(engine:print())

player = Node()
player:setPosition(0, -1.4, -10)
player:setColor(Colorf(1.0,1,1,.1))
enemy  = Node(0, 0, -11)
enemy:setColor(Colorf(0.0,1,0,.1))

print("Adding to scene")
local scene = engine:currentScene()
scene:addChild(player)
scene:addChild(enemy)
