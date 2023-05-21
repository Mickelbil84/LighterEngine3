local LRE3Object = require 'LRE3Object'

local Object = {}
function Object:new(ptr)
    o = setmetatable({ptr=ptr}, {__index = self})
    return o
end

function Object:get_name()
    return LRE3Object.GetName(self.ptr)
end

return Object