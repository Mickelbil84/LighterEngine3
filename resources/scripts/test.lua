local LRE3Input = require 'LRE3Input'

local assets = scene:get_assets()
assets:load_shader("S_base", "resources/shaders/base.vs", "resources/shaders/base.fs")
assets:load_texture("T_penguin", "resources/textures/animals/penguin.png")
assets:load_texture("T_giraffe", "resources/textures/animals/giraffe.png")

scene:get_camera():set_zoom(0.37)
-----

Player = require 'Player'
player = Player:new('penguin', 'S_base', 'T_penguin')
player.speed = 2.0