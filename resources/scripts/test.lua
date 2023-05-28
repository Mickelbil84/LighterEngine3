local LRE3Input = require 'LRE3Input'

local assets = scene:get_assets()
assets:load_shader("S_base", "resources/shaders/base.vs", "resources/shaders/base.fs")

assets:load_texture("T_spritesheet", "resources/textures/dungeon/spritesheet.png")
assets:set_texture_atlas_size("T_spritesheet", 9, 28)

assets:load_texture("T_tilemap", "resources/textures/dungeon/tilemap.png")
assets:set_texture_atlas_size("T_tilemap", 8, 9)

scene:get_camera():set_zoom(0.7)
-----

local Player = require 'Player'
local player = Player:new('knight', 'S_base', 'T_spritesheet')
player.speed = 4.0
player:set_position(-1, -1)
player:set_scale(0.15, 0.15)
player:set_depth(1.0)
player.sprite:add_animation("idle", 140, 6, 10)
player.sprite:add_animation("run", 168, 6, 16)
player.sprite:set_animation("idle")

player.original_update = player.update
function player:update(delta_time)
    self:original_update(delta_time)
    
    -- Set animation
    if ((self.dx ~= 0) or (self.dy ~= 0)) then self.sprite:set_animation("run") 
    else self.sprite:set_animation("idle") end 

    -- Set horizontal flip
    if (self.dx < 0) then self.sprite:set_flip_horizontal(true) end
    if (self.dx > 0) then self.sprite:set_flip_horizontal(false) end
    
end

------------------

local tiledemo = scene:add_sprite('tiledemo', 'S_base', 'T_tilemap')

local tile_floor <const> = 11

tiles = {}
rows = 40; cols = 40;
for i=1,(rows * cols) do 
    tiles[i] = tile_floor
end
tiledemo:set_tiles_from_table(rows, cols, tiles)
tiledemo:set_position(-0.5,-0.5)
tiledemo:set_scale(5, 5)

local pooltable = scene:add_sprite('pooltable', 'S_base', 'T_tilemap')
pooltable:set_scale(0.3, 0.15)
pooltable:set_tiles_from_table(1, 2, {9, 10})
pooltable:set_depth(0.5)

local test = scene:add_animated_sprite('test', 'S_base', 'T_spritesheet')
test:set_depth(0.9)
test:add_animation("idle", 140, 6, 16)
test:add_animation("run", 168, 6, 8)
test:set_animation("run")