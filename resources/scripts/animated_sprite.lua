local AnimatedSprite = {}

function AnimatedSprite:new(name, shader, texture)
    local obj = scene:add_sprite(name, shader, texture)
    obj:set_tile_shape(1, 1)
    obj.update = self.update
    obj.add_animation = self.add_animation
    obj.set_animation = self.set_animation
    obj.get_curr_animation = self.get_curr_animation

    obj.animations = {}
    obj.curr_animation = nil

    obj.run_time = 0.0
    obj.last_frame_time = 0.0
    obj.curr_frame = 0
    return obj
end

function AnimatedSprite:get_curr_animation()
    return self.animations[self.curr_animation]
end

function AnimatedSprite:add_animation(name, frame_start, frame_end, fps)
    self.animations[name] = {
        frame_start=frame_start, 
        frame_end=frame_end,
        fps=fps
    }
end

function AnimatedSprite:set_animation(name)
    if self.curr_animation == name then return end
    self.curr_animation = name
    self.curr_frame = 0
    self.last_frame_time = self.run_time
    self:set_tile(0, 0, self:get_curr_animation().frame_start)
end

function AnimatedSprite:update(delta_time)
    self.run_time = self.run_time + delta_time
    
    if self.curr_animation then 
        if self.run_time > self.last_frame_time + (1 / self:get_curr_animation().fps) then
            self.curr_frame = self.curr_frame + 1
            if self:get_curr_animation().frame_start + self.curr_frame > self:get_curr_animation().frame_end then
                self.curr_frame = 0
            end
            self:set_tile(0, 0, self:get_curr_animation().frame_start + self.curr_frame)
            self.last_frame_time = self.run_time
            print(self:get_curr_animation().frame_start + self.curr_frame)
        end
    end 
end

return AnimatedSprite