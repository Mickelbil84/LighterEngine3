#pragma once

#include "../lre3_engine_subsystems.h"

// Binding macros, for shorter code
#define GET_BOOL(varname, idx) bool varname = LRE3GetScriptSystem().GetBool(idx);
#define GET_NUMBER(varname, idx) double varname = LRE3GetScriptSystem().GetNumber(idx);
#define GET_STRING(varname, idx) std::string varname = LRE3GetScriptSystem().GetString(idx);

#define GET_UDATA(varname, type, idx) type* varname = (type*)(LRE3GetScriptSystem().GetUserType(idx, #type));
#define GET_SELF(type) GET_UDATA(self, type, 1)

#define PUSH_NIL() LRE3GetScriptSystem().PushNil();
#define PUSH_BOOL(b) LRE3GetScriptSystem().PushBool((b));
#define PUSH_NUMBER(n) LRE3GetScriptSystem().PushNumber((n));
#define PUSH_STRING(s) LRE3GetScriptSystem().PushString((s));
#define PUSH_UDATA(udata, type) LRE3GetScriptSystem().PushUserType((void*)(udata), #type);

#define REGISTER(type) do {luaL_requiref(L, #type, luaopen_##type, 1); LRE3GetScriptSystem().RegisterClass(#type);} while(0);
#define REGISTER_OOP(type, base) do {luaL_requiref(L, #type, luaopen_##type, 1); LRE3GetScriptSystem().RegisterClass(#type, #base);} while(0);