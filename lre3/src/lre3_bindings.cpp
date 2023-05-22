#include "lre3_bindings.h"

void LRE3Bind()
{
    lua_State* L = LRE3GetScriptSystem().GetState();

    luaL_requiref(L, "LRE3SceneManager", luaopen_LRE3SceneManager, 1);
    LRE3GetScriptSystem().RegisterClass("LRE3SceneManager");
    luaL_requiref(L, "LRE3AssetManager", luaopen_LRE3AssetManager, 1);
    LRE3GetScriptSystem().RegisterClass("LRE3AssetManager");

    luaL_requiref(L, "LRE3Object", luaopen_LRE3Object, 1);
    LRE3GetScriptSystem().RegisterClass("LRE3Object");

    luaL_requiref(L, "LRE3Texture", luaopen_LRE3Texture, 1);
    LRE3GetScriptSystem().RegisterClass("LRE3Texture");
    luaL_requiref(L, "LRE3Shader", luaopen_LRE3Shader, 1);
    LRE3GetScriptSystem().RegisterClass("LRE3Shader");
}

//////////////////////////////////////////////////////

static int LRE3Object_GetName(lua_State* L)
{
    LRE3Object* obj = (LRE3Object*)(LRE3GetScriptSystem().GetUserType(1, "LRE3Object"));
    LRE3GetScriptSystem().PushString(obj->GetName());
    return 1;
}

static const luaL_Reg LRE3Object_lib[] = {
    {"get_name", LRE3Object_GetName},
    {NULL, NULL}
};
int luaopen_LRE3Object(lua_State* L)
{
    luaL_newlib(L, LRE3Object_lib);
    return 1;
}

//////////////////////////////////////////////////////

void SetSceneGlobal(LRE3SceneManager* scene)
{
    LRE3GetScriptSystem().PushUserType((void*) scene, "LRE3SceneManager");
    LRE3GetScriptSystem().SetGlobal("scene");
}

static int LRE3SceneManager_GetAssets(lua_State* L)
{
    LRE3SceneManager* self = (LRE3SceneManager*)(LRE3GetScriptSystem().GetUserType(1, "LRE3SceneManager"));
    LRE3AssetManager* assets = &(self->assets);
    LRE3GetScriptSystem().PushUserType((void*)assets, "LRE3AssetManager");
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

static const luaL_Reg LRE3SceneManager_lib[] = {
    {"get_object", LRE3SceneManager_GetObject},
    {"get_assets", LRE3SceneManager_GetAssets},
    {NULL, NULL}
};

int luaopen_LRE3SceneManager(lua_State* L)
{
    luaL_newlib(L, LRE3SceneManager_lib);
    return 1;
}

//////////////////////////////////////////////////////

static const luaL_Reg LRE3Texture_lib[] = {
    {NULL, NULL}
};
int luaopen_LRE3Texture(lua_State* L)
{
    luaL_newlib(L, LRE3Texture_lib);
    return 1;
}

//////////////////////////////////////////////////////

static const luaL_Reg LRE3Shader_lib[] = {
    {NULL, NULL}
};
int luaopen_LRE3Shader(lua_State* L)
{
    luaL_newlib(L, LRE3Shader_lib);
    return 1;
}

//////////////////////////////////////////////////////

static int LRE3AssetManager_LoadTexture(lua_State* L)
{
    LRE3AssetManager* self = (LRE3AssetManager*)(LRE3GetScriptSystem().GetUserType(1, "LRE3AssetManager"));
    std::string name = LRE3GetScriptSystem().GetString(2);
    std::string path = LRE3GetScriptSystem().GetString(3);
    self->LoadTexture(name, path);
    return 0;
}
static int LRE3AssetManager_GetTexture(lua_State* L)
{
    LRE3AssetManager* self = (LRE3AssetManager*)(LRE3GetScriptSystem().GetUserType(1, "LRE3AssetManager"));
    std::string name = LRE3GetScriptSystem().GetString(2);
    LRE3GetScriptSystem().PushUserType((void*)self->GetTexture(name), "LRE3Texture");
    return 1;
}
static int LRE3AssetManager_LoadShader(lua_State* L)
{
    LRE3AssetManager* self = (LRE3AssetManager*)(LRE3GetScriptSystem().GetUserType(1, "LRE3AssetManager"));
    std::string name = LRE3GetScriptSystem().GetString(2);
    std::string vs_path = LRE3GetScriptSystem().GetString(3);
    std::string fs_path = LRE3GetScriptSystem().GetString(4);
    self->LoadShader(name, vs_path, fs_path);
    return 0;
}
static int LRE3AssetManager_GetShader(lua_State* L)
{
    LRE3AssetManager* self = (LRE3AssetManager*)(LRE3GetScriptSystem().GetUserType(1, "LRE3AssetManager"));
    std::string name = LRE3GetScriptSystem().GetString(2);
    LRE3GetScriptSystem().PushUserType((void*)self->GetShader(name), "LRE3Shader");
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