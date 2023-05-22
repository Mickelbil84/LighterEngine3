#include "lre3_object_binding.h"

static int LRE3Object_GetName(lua_State* L);

static const luaL_Reg LRE3Object_lib[] = {
    {"get_name", LRE3Object_GetName},
    {NULL, NULL}
};

int luaopen_LRE3Object(lua_State* L)
{
    luaL_newlib(L, LRE3Object_lib);
    return 1;
}

static int LRE3Object_GetName(lua_State* L)
{
    LRE3Object* obj = (LRE3Object*)(LRE3GetScriptSystem().GetUserType(1, "LRE3Object"));
    LRE3GetScriptSystem().PushString(obj->GetName());
    return 1;
}