#include "lre3_bindings.h"

void LRE3Bind()
{
    lua_State* L = LRE3GetScriptSystem().GetState();

    REGISTER(LRE3SceneManager);
    REGISTER(LRE3AssetManager);

    REGISTER(LRE3Texture);
    REGISTER(LRE3Shader);

    REGISTER(LRE3Object);
    REGISTER_OOP(LRE3Camera, LRE3Object);
    REGISTER_OOP(LRE3SceneRoot, LRE3Object);
    REGISTER_OOP(LRE3SpriteObject, LRE3Object);
}

//////////////////////////////////////////////////////

static int LRE3Object_SetPosition(lua_State* L)
{
    GET_SELF(LRE3Object);
    GET_NUMBER(x, 2);
    GET_NUMBER(y, 3);
    self->SetPosition(glm::vec2(x,y));
    return 0;
}
static int LRE3Object_SetRotation(lua_State* L)
{
    GET_SELF(LRE3Object);
    GET_NUMBER(rotation, 2);
    self->SetRotation(rotation);
    return 0;
}
static int LRE3Object_SetScale(lua_State* L)
{
    GET_SELF(LRE3Object);
    GET_NUMBER(x, 2);
    GET_NUMBER(y, 3);
    self->SetScale(glm::vec2(x,y));
    return 0;
}
static int LRE3Object_GetPosition(lua_State* L)
{
    GET_SELF(LRE3Object);
    glm::vec2 pos = self->GetPosition();
    PUSH_NUMBER(pos.x);
    PUSH_NUMBER(pos.y);
    return 2;
}
static int LRE3Object_GetRotation(lua_State* L)
{
    GET_SELF(LRE3Object);
    PUSH_NUMBER(self->GetRotation());
    return 1;
}
static int LRE3Object_GetScale(lua_State* L)
{
    GET_SELF(LRE3Object);
    glm::vec2 scale = self->GetScale();
    PUSH_NUMBER(scale.x);
    PUSH_NUMBER(scale.y);
    return 2;
}
static int LRE3Object_SetName(lua_State* L)
{
    GET_SELF(LRE3Object);
    GET_STRING(name, 2);
    self->SetName(name);
    return 0;
}
static int LRE3Object_GetName(lua_State* L)
{
    GET_SELF(LRE3Object);
    PUSH_STRING(self->GetName());
    return 1;
}
static int LRE3Object_SetHiddenInSceneGraph(lua_State* L)
{
    GET_SELF(LRE3Object);
    GET_BOOL(hidden, 2);
    self->SetHiddenInSceneGraph(hidden);
    return 0;
}
static int LRE3Object_GetHiddenInSceneGraph(lua_State* L)
{
    GET_SELF(LRE3Object);
    PUSH_BOOL(self->GetHiddenInSceneGraph());
    return 1;
}
static int LRE3Object_SetHidden(lua_State* L)
{
    GET_SELF(LRE3Object);
    GET_BOOL(hidden, 2);
    self->SetHidden(hidden);
    return 0;
}
static int LRE3Object_GetHidden(lua_State* L)
{
    GET_SELF(LRE3Object);
    PUSH_BOOL(self->GetHidden());
    return 1;
}
static int LRE3Object_SetSelected(lua_State* L)
{
    GET_SELF(LRE3Object);
    GET_BOOL(selected, 2);
    self->SetSelected(selected);
    return 0;
}
static int LRE3Object_GetSelected(lua_State* L)
{
    GET_SELF(LRE3Object);
    PUSH_BOOL(self->GetSelected());
    return 1;
}

static const luaL_Reg LRE3Object_lib[] = {
    {"set_position", LRE3Object_SetPosition},
    {"set_rotation", LRE3Object_SetRotation},
    {"set_scale", LRE3Object_SetScale},
    {"get_position", LRE3Object_GetPosition},
    {"get_rotation", LRE3Object_GetRotation},
    {"get_scale", LRE3Object_GetScale},
    {"set_name", LRE3Object_SetName},
    {"get_name", LRE3Object_GetName},
    {"set_hidden_in_scene_graph", LRE3Object_SetHiddenInSceneGraph},
    {"get_hidden_in_scene_graph", LRE3Object_GetHiddenInSceneGraph},
    {"set_hidden", LRE3Object_SetHidden},
    {"get_hidden", LRE3Object_GetHidden},
    {"set_selected", LRE3Object_SetSelected},
    {"get_selected", LRE3Object_GetSelected},
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

//////////////////////////////////////////////////////

static int LRE3Camera_GetZoom(lua_State* L)
{
    GET_SELF(LRE3Camera);
    double zoom = self->GetZoom();
    PUSH_NUMBER(zoom);
    return 1;
}

static int LRE3Camera_SetZoom(lua_State* L)
{
    GET_SELF(LRE3Camera);
    GET_NUMBER(zoom, 2);
    self->SetZoom(zoom);
    return 0;
}

static const luaL_Reg LRE3Camera_lib[] = {
    {"get_zoom", LRE3Camera_GetZoom},
    {"set_zoom", LRE3Camera_SetZoom},
    {NULL, NULL}
};
int luaopen_LRE3Camera(lua_State* L)
{
    luaL_newlib(L, LRE3Camera_lib);
    return 1;
}

//////////////////////////////////////////////////////

static int LRE3Input_GetKeystate(lua_State* L)
{
    GET_SELF(LRE3Input);
    GET_NUMBER(scancode, 2);
    PUSH_BOOL((bool)self->keyboard[(int)scancode]);
    return 1;
}

static int LRE3Input_GetMouseRel(lua_State* L)
{
    GET_SELF(LRE3Input);
    PUSH_NUMBER((double)self->xrel);
    PUSH_NUMBER((double)self->yrel);
    return 2;
}

static int LRE3Input_GetLMouseDown(lua_State* L)
{
    GET_SELF(LRE3Input);
    PUSH_BOOL(self->bLeftMouseDown);
    return 1;
}

static int LRE3Input_GetRMouseDown(lua_State* L)
{
    GET_SELF(LRE3Input);
    PUSH_BOOL(self->bRightMouseDown);
    return 1;
}

static const luaL_Reg LRE3Input_lib[] = {
    {"get_keystate", LRE3Input_GetKeystate},
    {"get_mouse_rel", LRE3Input_GetMouseRel},
    {"get_lmouse_down", LRE3Input_GetLMouseDown},
    {"get_rmouse_down", LRE3Input_GetRMouseDown},
    {NULL, NULL}
};
int luaopen_LRE3Input(lua_State* L)
{
    luaL_newlib(L, LRE3Input_lib);
    return 1;
}

//////////////////////////////////////////////////////

static const luaL_Reg LRE3SceneRoot_lib[] = {
    {NULL, NULL}
};
int luaopen_LRE3SceneRoot(lua_State* L)
{
    luaL_newlib(L, LRE3SceneRoot_lib);
    return 1;
}

//////////////////////////////////////////////////////

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