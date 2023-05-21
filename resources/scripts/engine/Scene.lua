local LRE3SceneManager = require 'LRE3SceneManager'

local Object = require 'engine.Object'
local Scene = {ptr=g_scene_ptr}

function Scene:get_object(name)
    obj_ptr = LRE3SceneManager.GetObject(self.ptr, name)
    return Object:new(obj_ptr)
end

return Scene