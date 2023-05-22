local LRE3SceneManager = require 'LRE3SceneManager'

local Object = require 'engine.Object'
local Scene = {ptr=g_scene_ptr, obj_ptr_table={}}

function Scene:get_object(name)
    obj_ptr = LRE3SceneManager.GetObject(self.ptr, name)
    if not self.obj_ptr_table[obj_ptr] then self.obj_ptr_table[obj_ptr] = Object:new(obj_ptr) end
    return self.obj_ptr_table[obj_ptr]
end

return Scene