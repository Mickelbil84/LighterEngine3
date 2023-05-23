#include "lre3_bindings.h"


static const luaL_Reg LRE3Texture_lib[] = {
    {NULL, NULL}
};
int luaopen_LRE3Texture(lua_State* L)
{
    luaL_newlib(L, LRE3Texture_lib);
    return 1;
}
