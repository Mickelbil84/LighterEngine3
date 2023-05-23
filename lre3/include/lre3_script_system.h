#pragma once

#include <iostream>
#include <string>
#include <cassert>
#include <fmt/format.h>

#include <lua.hpp>
#include <lauxlib.h>

#include "lre3_events.h"
#include "lre3_object.h"

using fmt::format;

#define LUA_PRINT_ERROR(L) (luaL_error(L, "Error: %s", lua_tostring(L, -1)))
#define LUA_BINDING_TABLE "_g_binding_table"

class LRE3ScriptObserver : public LRE3Observer<LRE3Object>
{
public:
    void SetState(lua_State* L);
    virtual void OnNotify(LRE3Object* sender, LRE3EventType eventType);

protected:
    lua_State* L;
};

class LRE3ScriptSystem
{
public:
    LRE3ScriptSystem();
    void Init();
    void Shutdown();

    // General methods
    bool AddDirectoryToPath(std::string path);
    bool DoString(std::string str);
    bool DoFile(std::string filename);

    // 
    // Binding functions
    //
    int RegisterClass(std::string classname, std::string baseclass="");

    void PushNil();
    void PushBool(bool b);
    void PushNumber(double n);
    void PushString(std::string str);
    void PushUserType(void* udata, std::string tname);

    bool GetBool(int index);
    double GetNumber(int index);
    std::string GetString(int index);
    std::string GetStringOrNil(int index);
    void* GetUserType(int index, std::string tname, std::string* actual_tname=nullptr);

    void ReleaseUserType(void* udata);

    void SetGlobal(std::string name);

    lua_State* GetState() const;

    LRE3ScriptObserver scriptObserver;


private:
    int CheckUserType(void* udata, std::string tname);

    lua_State* L;
    bool m_bInitialized;
};