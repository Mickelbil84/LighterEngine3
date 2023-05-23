local assets = scene:get_assets()
assets:load_shader("S_base", "resources/shaders/base.vs", "resources/shaders/base.fs")
assets:load_texture("T_penguin", "resources/textures/animals/penguin.png")
assets:load_texture("T_giraffe", "resources/textures/animals/giraffe.png")

-----

scene:get_camera():set_zoom(0.37)

local penguin = scene:add_sprite("penguin", "S_base", "T_penguin")
penguin:set_position(0, -0.5)
penguin:set_rotation(0.3)
penguin:set_scale(0.9, 1.1)

local giraffe = scene:add_sprite("giraffe", "S_base", "T_giraffe")
giraffe:set_depth(1.0)
giraffe.run_time = 0.0
function giraffe:update(delta_time)
    self.run_time = self.run_time + delta_time
    giraffe:set_position(math.sin(self.run_time), 0.0)
end

local penguin2 = scene:duplicate_object(penguin, "")
penguin2:set_rotation(0.0)
penguin2:set_depth(-1.0)
penguin2.run_time = 0.0
function penguin2:update(delta_time)
    self.run_time = self.run_time + delta_time
    penguin2:set_position(math.cos(self.run_time), -0.3)
end