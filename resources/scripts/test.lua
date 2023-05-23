local assets = scene:get_assets()
assets:load_texture("T_giraffe", "resources/textures/animals/giraffe.png")

-----

scene:get_camera():set_zoom(0.37)

local penguin = scene:get_sprite("penguin")
local x, y = penguin:get_position()
local r = penguin:get_rotation()
local sx, sy = penguin:get_scale()
penguin:set_position(x+0.1, y-0.1)
penguin:set_rotation(r+0.3)
penguin:set_scale(sx*0.9, sy*1.1)

local giraffe = scene:add_sprite("giraffe", "S_base", "T_giraffe")
giraffe:set_position(1.0, 0.0)

giraffe.run_time = 0.0
function giraffe:update(delta_time)
    self.run_time = self.run_time + delta_time
    giraffe:set_position(math.sin(self.run_time), 0.0)
end


local penguin2 = scene:duplicate_object(penguin, "")
print(penguin2, penguin2:get_name())
penguin2:set_position(x-1.5, y)
penguin2:set_rotation(0.0)