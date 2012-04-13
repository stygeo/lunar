print("Hello world")

print(engine:print())

player = Node(0, 0, -.5)
enemy  = Node(-.5, -.4, 0)
enemy2 = Node(.5, .3, -1)

print("Adding to scene")
local scene = engine:currentScene()
scene:addChild(player)
scene:addChild(enemy)
scene:addChild(enemy2)
