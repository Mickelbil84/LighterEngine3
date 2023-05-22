-- penguin = scene:get_object("penguin")
-- penguin.health = 100
-- penguin.damage = function (self, amount) self.health = self.health - amount end
-- print(penguin.health)
-- penguin:damage(10)
-- print(penguin.health)

-- penguin2 = scene:get_object("penguin")
-- print(penguin2.health)

----

local assets = scene:get_assets()
print(scene, assets)

local shader1 = assets:get_shader("S_base")
local texture1 = assets:get_texture("T_penguin")
print(shader1, texture1)

assets:load_shader("S_base2", "resources/shaders/base.vs", "resources/shaders/base.fs")
assets:load_texture("T_giraffe", "resources/textures/animals/giraffe.png")
print(assets:get_shader("S_base2"), assets:get_texture("T_giraffe"))