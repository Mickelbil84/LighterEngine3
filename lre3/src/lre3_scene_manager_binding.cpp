#include "lre3_scene_manager_binding.h"

void SetSceneGlobal(LRE3SceneManager* scene)
{
    LRE3GetScriptSystem().PushUserType((void*) scene, "LRE3SceneManager");
    LRE3GetScriptSystem().SetGlobal("scene");
}

static int LRE3SceneManager_GetObject(lua_State* L);

static const luaL_Reg LRE3SceneManager_lib[] = {
    {"get_object", LRE3SceneManager_GetObject},
    {NULL, NULL}
};

extern "C" int luaopen_LRE3SceneManager(lua_State* L)
{
    luaL_newlib(L, LRE3SceneManager_lib);
    return 1;
}

static int LRE3SceneManager_GetObject(lua_State* L)
{
    LRE3SceneManager* self = (LRE3SceneManager*)(LRE3GetScriptSystem().GetUserType(1, "LRE3SceneManager"));
    std::string name = LRE3GetScriptSystem().GetString(2);
    LRE3Object* obj = self->GetObject(name).get();
    LRE3GetScriptSystem().PushUserType((void*)obj, "LRE3Object");
    return 1;
}