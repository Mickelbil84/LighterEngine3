#include "bindings/lre3_camera_binding.h"


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