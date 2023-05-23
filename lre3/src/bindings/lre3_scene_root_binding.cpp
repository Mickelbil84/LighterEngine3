#include "lre3_bindings.h"


static const luaL_Reg LRE3SceneRoot_lib[] = {
    {NULL, NULL}
};
int luaopen_LRE3SceneRoot(lua_State* L)
{
    luaL_newlib(L, LRE3SceneRoot_lib);
    return 1;
}
