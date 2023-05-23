#include "bindings/lre3_shader_binding.h"


static const luaL_Reg LRE3Shader_lib[] = {
    {NULL, NULL}
};
int luaopen_LRE3Shader(lua_State* L)
{
    luaL_newlib(L, LRE3Shader_lib);
    return 1;
}
