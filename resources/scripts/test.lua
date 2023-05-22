penguin = scene:get_object("penguin")
penguin.health = 100
penguin.damage = function (self, amount) self.health = self.health - amount end
print(penguin.health)
penguin:damage(10)
print(penguin.health)

penguin2 = scene:get_object("penguin")
print(penguin2.health)