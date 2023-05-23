#include "bindings/lre3_object_binding.h"


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