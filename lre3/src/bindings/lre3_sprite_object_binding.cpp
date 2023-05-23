#include "lre3_bindings.h"


FBIND(LRE3SpriteObject, SetShader)
{   
    GET_SELF(LRE3SpriteObject);
    GET_UDATA(shader, LRE3Shader, 2);
    self->SetShader(shader);
    return 0;
}

FBIND(LRE3SpriteObject, SetTexture)
{
    GET_SELF(LRE3SpriteObject);
    GET_UDATA(texture, LRE3Texture, 2);
    self->SetTexture(texture);
    return 0;
}

LIB(LRE3SpriteObject) = {
    {"set_shader", FNAME(LRE3SpriteObject, SetShader)},
    {"set_texture", FNAME(LRE3SpriteObject, SetTexture)},
    {NULL, NULL}
};
LOPEN(LRE3SpriteObject)