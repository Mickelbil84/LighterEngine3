local Player = {}

function Player:new(name, shader, texture)
    local o = scene:add_object(name)
    o.sprite = scene:add_animated_sprite(name .. "_sprite", shader, texture)
    scene:reparent(o.sprite, o)
    o.speed = 1.0
    o.dx = 0.0; o.dy = 0.0;
    o.update = self.update

    o.frame_cnt = 0
    o.frame_time = 0
    return o
end

function Player:update(delta_time)
    local input = LRE3Input:get_input()
    self.dx, self.dy = 0, 0
    if input:get_keystate(SCANCODE_D) then self.dx = self.dx + self.speed * delta_time end
    if input:get_keystate(SCANCODE_A) then self.dx = self.dx - self.speed * delta_time end
    if input:get_keystate(SCANCODE_W) then self.dy = self.dy + self.speed * delta_time end
    if input:get_keystate(SCANCODE_S) then self.dy = self.dy - self.speed * delta_time end
    self:add_position(self.dx, self.dy)

    self.frame_cnt = self.frame_cnt + 1
    self.frame_time = self.frame_time + delta_time
    if self.frame_cnt == 500 then
        local avg_time = self.frame_time / self.frame_cnt
        -- print("FPS:", math.ceil(1 / avg_time))
        self.frame_cnt = 0
        self.frame_time = 0
    end
end

return Player