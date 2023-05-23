local Player = {}

function Player:new(name, shader, texture)
    local p = scene:add_sprite(name, shader, texture)
    p.speed = 1.0
    p.update = self.update

    p.frame_cnt = 0
    p.frame_time = 0
    return p
end

function Player:update(delta_time)
    local input = LRE3Input:get_input()
    local dx = 0.0; local dy = 0.0
    if input:get_keystate(SCANCODE_D) then dx = dx + self.speed * delta_time end
    if input:get_keystate(SCANCODE_A) then dx = dx - self.speed * delta_time end
    if input:get_keystate(SCANCODE_W) then dy = dy + self.speed * delta_time end
    if input:get_keystate(SCANCODE_S) then dy = dy - self.speed * delta_time end
    self:add_position(dx, dy)

    self.frame_cnt = self.frame_cnt + 1
    self.frame_time = self.frame_time + delta_time
    if self.frame_cnt == 500 then
        local avg_time = self.frame_time / self.frame_cnt
        print("FPS:", math.ceil(1 / avg_time))
        self.frame_cnt = 0
        self.frame_time = 0
    end
end

return Player