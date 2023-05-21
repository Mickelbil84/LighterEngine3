Scene = require 'engine.Scene'
Object = require 'engine.Object'

penguin = Scene:get_object("penguin")
print(penguin:get_name())

-- print(scene)

-- LRE3SceneManager = require 'LRE3SceneManager'
-- LRE3Object = require 'LRE3Object'
-- print('hi', LRE3SceneManager, LRE3Object)

-- obj = LRE3SceneManager.GetObject(scene, "penguin")
-- print(obj)
-- print(LRE3Object.GetName(obj))
-- -- print('hi', scene)
-- -- -- print(scene, scene.get_object)
-- -- -- obj2 = scene:get_object("penguin")
-- -- print(obj:get_name())
-- -- print(obj:get_name())