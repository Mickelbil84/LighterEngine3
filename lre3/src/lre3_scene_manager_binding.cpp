#include "lre3_scene_manager_binding.h"

void SetSceneGlobal(LRE3SceneManager* scene)
{
    LRE3GetScriptSystem().PushUserType((void*) scene, "LRE3SceneManager");
    LRE3GetScriptSystem().SetGlobal("scene");
}

static const luaL_Reg LRE3SceneManager_lib[] = {
    {NULL, NULL}
};

int luaopen_LRE3SceneManager(lua_State* L)
{
    LRE3GetScriptSystem().RegisterClass("LRE3SceneManager");
    luaL_setfuncs(L, LRE3SceneManager_lib, 0);
    return 1;
}