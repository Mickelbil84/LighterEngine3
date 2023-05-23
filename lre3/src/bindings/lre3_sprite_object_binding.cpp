#include "lre3_bindings.h"


static int LRE3SpriteObject_SetShader(lua_State* L)
{   
    GET_SELF(LRE3SpriteObject);
    GET_UDATA(shader, LRE3Shader, 2);
    self->SetShader(shader);
    return 0;
}

static int LRE3SpriteObject_SetTexture(lua_State* L)
{
    GET_SELF(LRE3SpriteObject);
    GET_UDATA(texture, LRE3Texture, 2);
    self->SetTexture(texture);
    return 0;
}

static const luaL_Reg LRE3SpriteObject_lib[] = {
    {"set_shader", LRE3SpriteObject_SetShader},
    {"set_texture", LRE3SpriteObject_SetTexture},
    {NULL, NULL}
};
int luaopen_LRE3SpriteObject(lua_State* L)
{
    luaL_newlib(L, LRE3SpriteObject_lib);
    return 1;
}