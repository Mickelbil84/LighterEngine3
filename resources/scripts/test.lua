Scene = require 'engine.Scene'
Object = require 'engine.Object'

penguin = Scene:get_object("penguin")
penguin.health = 100
penguin.damage = function (self, amount) self.health = self.health - amount end
print(penguin.health)
penguin:damage(10)
print(penguin.health)

penguin2 = Scene:get_object("penguin")
print(penguin2.health)