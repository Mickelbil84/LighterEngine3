obj = scene:get_object("penguin")
print(obj:get_name())

obj.health = 100
obj.hit = function (self, amount) self.health = self.health - amount end

print(obj.health)
obj:hit(20)
print(obj.health)
