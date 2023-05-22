local assets = scene:get_assets()
print(scene, assets)
print(scene:get_root())
print()

assets:load_shader("S_base2", "resources/shaders/base.vs", "resources/shaders/base.fs")
assets:load_texture("T_giraffe", "resources/textures/animals/giraffe.png")

local camera = scene:get_camera()
print()
print(camera)
print(camera, camera:get_zoom(), camera:get_name())

local penguin = scene:get_sprite("penguin")
print()
print(penguin, penguin:get_name())
penguin:set_texture(assets:get_texture("T_giraffe"))