#include "lre3_bindings.h"

void LRE3Bind()
{
    lua_State* L = LRE3GetScriptSystem().GetState();

    luaL_requiref(L, "LRE3SceneManager", luaopen_LRE3SceneManager, 1);
    luaL_requiref(L, "LRE3Object", luaopen_LRE3Object, 1);
    // luaopen_lre3scenemanager(L);
    // luaopen_LRE3Object(L);
}