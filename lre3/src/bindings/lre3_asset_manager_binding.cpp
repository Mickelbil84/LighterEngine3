#include "bindings/lre3_asset_manager_binding.h"


static int LRE3AssetManager_LoadTexture(lua_State* L)
{
    GET_SELF(LRE3AssetManager);
    GET_STRING(name, 2);
    GET_STRING(path, 3);
    self->LoadTexture(name, path);
    return 0;
}
static int LRE3AssetManager_GetTexture(lua_State* L)
{
    GET_SELF(LRE3AssetManager);
    GET_STRING(name, 2);
    PUSH_UDATA(self->GetTexture(name), LRE3Texture);
    return 1;
}
static int LRE3AssetManager_LoadShader(lua_State* L)
{
    GET_SELF(LRE3AssetManager);
    GET_STRING(name, 2);
    GET_STRING(vs_path, 3);
    GET_STRING(fs_path, 4);
    self->LoadShader(name, vs_path, fs_path);
    return 0;
}
static int LRE3AssetManager_GetShader(lua_State* L)
{
    GET_SELF(LRE3AssetManager);
    GET_STRING(name, 2);
    PUSH_UDATA(self->GetShader(name), LRE3Shader);
    return 1;
}

static const luaL_Reg LRE3AssetManager_lib[] = {
    {"load_texture", LRE3AssetManager_LoadTexture},
    {"get_texture", LRE3AssetManager_GetTexture},
    {"load_shader", LRE3AssetManager_LoadShader},
    {"get_shader", LRE3AssetManager_GetShader},
    {NULL, NULL}
};
int luaopen_LRE3AssetManager(lua_State* L)
{
    luaL_newlib(L, LRE3AssetManager_lib);
    return 1;
}
