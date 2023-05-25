local LRE3Input = require 'LRE3Input'

local assets = scene:get_assets()
assets:load_shader("S_base", "resources/shaders/base.vs", "resources/shaders/base.fs")
assets:load_texture("T_penguin", "resources/textures/animals/penguin.png")
assets:load_texture("T_giraffe", "resources/textures/animals/giraffe.png")

assets:load_texture("T_knight", "resources/textures/knight.png")
assets:set_texture_atlas_size("T_knight", 2, 6)

assets:load_texture("T_demo_tilesheet", "resources/textures/demo_tilesheet.png")
assets:set_texture_atlas_size("T_demo_tilesheet", 22, 49)

scene:get_camera():set_zoom(0.37)
-----

local Player = require 'Player'
local player = Player:new('knight', 'S_base', 'T_knight')
player.speed = 4.0
player:set_position(-1, -1)
player:set_scale(0.2, 0.2)
player:set_depth(1.0)
print(player.sprite.add_animation)
player.sprite:add_animation("idle", 0, 5, 10)
player.sprite:add_animation("run", 6, 11, 16)
player.sprite:set_animation("idle")

player.original_update = player.update
function player:update(delta_time)
    self:original_update(delta_time)
    
    -- Set animation
    if ((self.dx ~= 0) or (self.dy ~= 0)) then self.sprite:set_animation("run") 
    else self.sprite:set_animation("idle"); print(self.sprite.curr_animation) end 

    -- Set horizontal flip
    if (self.dx < 0) then self.sprite:set_flip_horizontal(true) end
    if (self.dx > 0) then self.sprite:set_flip_horizontal(false) end

    
end

------------------

local tiledemo = scene:add_sprite('tiledemo', 'S_base', 'T_demo_tilesheet')
tiles = {}
rows = 9; cols = 8;
for i=1,(rows * cols) do 
    tiles[i] = math.random(0, 60)
end
tiledemo:set_tiles_from_table(rows, cols, tiles)
