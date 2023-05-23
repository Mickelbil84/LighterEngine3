#include "bindings/lre3_scene_manager_binding.h"


void SetSceneGlobal(LRE3SceneManager* scene)
{
    LRE3GetScriptSystem().PushUserType((void*) scene, "LRE3SceneManager");
    LRE3GetScriptSystem().SetGlobal("scene");
}

static int LRE3SceneManager_GetAssets(lua_State* L)
{
    GET_SELF(LRE3SceneManager);
    PUSH_UDATA(&(self->assets), LRE3AssetManager);
    return 1;
}

static int LRE3SceneManager_GetCamera(lua_State* L)
{
    GET_SELF(LRE3SceneManager);
    PUSH_UDATA(self->GetCamera().get(), LRE3Camera);
    return 1;
}

static int LRE3SceneManager_GetSprite(lua_State* L)
{
    GET_SELF(LRE3SceneManager);
    GET_STRING(name, 2);
    PUSH_UDATA(self->GetSprite(name).get(), LRE3SpriteObject);
    return 1;
}

static int LRE3SceneManager_GetRoot(lua_State* L)
{
    GET_SELF(LRE3SceneManager);
    PUSH_UDATA(self->GetRoot().get(), LRE3SceneRoot);
    return 1;
}

static int LRE3SceneManager_GetObject(lua_State* L)
{
    GET_SELF(LRE3SceneManager);
    GET_STRING(name, 2);
    PUSH_UDATA(self->GetObject(name).get(), LRE3Object);
    return 1;
}

static const luaL_Reg LRE3SceneManager_lib[] = {
    {"get_object", LRE3SceneManager_GetObject},
    {"get_root", LRE3SceneManager_GetRoot},
    {"get_sprite", LRE3SceneManager_GetSprite},
    {"get_camera", LRE3SceneManager_GetCamera},
    {"get_assets", LRE3SceneManager_GetAssets},
    {NULL, NULL}
};

int luaopen_LRE3SceneManager(lua_State* L)
{
    luaL_newlib(L, LRE3SceneManager_lib);
    return 1;
}
