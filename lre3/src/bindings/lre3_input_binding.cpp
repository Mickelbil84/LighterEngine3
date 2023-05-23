#include "lre3_bindings.h"


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