#pragma once

#include "lre3_engine_subsystems.h"

#include "lre3_asset_manager.h"
#include "lre3_camera.h"
#include "lre3_input.h"
#include "lre3_object.h"
#include "lre3_scene_manager.h"
#include "lre3_scene_root.h"
#include "lre3_shader.h"
#include "lre3_sprite_object.h"
#include "lre3_texture.h"
#include "lre3_animated_sprite.h"


// Binding macros, for shorter code
#define GET_BOOL(varname, idx) bool varname = LRE3GetScriptSystem().GetBool(idx);
#define GET_NUMBER(varname, idx) double varname = LRE3GetScriptSystem().GetNumber(idx);
#define GET_STRING(varname, idx) std::string varname = LRE3GetScriptSystem().GetString(idx);
#define GET_STRING_OR_NIL(varname, idx) std::string varname = LRE3GetScriptSystem().GetStringOrNil(idx);

#define GET_UDATA(varname, type, idx) type* varname = (type*)(LRE3GetScriptSystem().GetUserType(idx, #type));
#define GET_UDATA_WITHTYPE(varname, type, idx) std::string actual_tname; type* varname = (type*)(LRE3GetScriptSystem().GetUserType(idx, #type, &actual_tname));
#define GET_SELF(type) GET_UDATA(self, type, 1)

#define PUSH_NIL() LRE3GetScriptSystem().PushNil();
#define PUSH_BOOL(b) LRE3GetScriptSystem().PushBool((b));
#define PUSH_NUMBER(n) LRE3GetScriptSystem().PushNumber((n));
#define PUSH_STRING(s) LRE3GetScriptSystem().PushString((s));
#define PUSH_UDATA(udata, type) LRE3GetScriptSystem().PushUserType((void*)(udata), #type);
#define PUSH_UDATA_STR(udata, type) LRE3GetScriptSystem().PushUserType((void*)(udata), type);

#define RELEASE_UDATA(udata) LRE3GetScriptSystem().ReleaseUserType((void*)(udata));

#define FNAME(type, foo) type##_##foo
#define FBIND(type, foo) static int FNAME(type, foo)(lua_State* L)
#define LIB(type) static const luaL_Reg type##_lib[]
#define LOPEN_DECLARE(type) int luaopen_##type(lua_State* L)
#define LOPEN(type) LOPEN_DECLARE(type){luaL_newlib(L, type##_lib); return 1;}
#define LOPEN_EMPTY(type) LIB(type) = {{NULL, NULL}}; LOPEN(type)

#define REGISTER(type) do {luaL_requiref(L, #type, luaopen_##type, 1); LRE3GetScriptSystem().RegisterClass(#type);} while(0);
#define REGISTER_OOP(type, base) do {luaL_requiref(L, #type, luaopen_##type, 1); LRE3GetScriptSystem().RegisterClass(#type, #base);} while(0);

#define ADD_SCANCODE(name, scancode) {LRE3GetScriptSystem().PushNumber(scancode); LRE3GetScriptSystem().SetGlobal(name); }


// ------------------------------------------------

void LRE3Bind();

void SetSceneGlobal(LRE3SceneManager* scene);
void AddScancodeGlobals();

LOPEN_DECLARE(LRE3SceneManager);
LOPEN_DECLARE(LRE3AssetManager);
LOPEN_DECLARE(LRE3Camera);
LOPEN_DECLARE(LRE3Input);
LOPEN_DECLARE(LRE3Object);
LOPEN_DECLARE(LRE3SceneRoot);
LOPEN_DECLARE(LRE3Shader);
LOPEN_DECLARE(LRE3SpriteObject);
LOPEN_DECLARE(LRE3Texture);
LOPEN_DECLARE(LRE3AnimatedSprite);