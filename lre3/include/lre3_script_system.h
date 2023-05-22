#pragma once

#include <iostream>
#include <string>
#include <fmt/format.h>

#include <lua.hpp>
#include <lauxlib.h>

using fmt::format;

#define LUA_PRINT_ERROR(L) (luaL_error(L, "Error: %s", lua_tostring(L, -1)))
#define LUA_BINDING_TABLE "_g_binding_table"

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
    void* GetUserType(int index, std::string tname);

    void ReleaseUserType(void* udata);

    void SetGlobal(std::string name);

    lua_State* GetState() const;




private:
    int CheckUserType(void* udata, std::string tname);

    lua_State* L;
    bool m_bInitialized;
};