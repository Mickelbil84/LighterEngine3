#include "lre3_script_system.h"

LRE3ScriptSystem::LRE3ScriptSystem():
    m_bInitialized(false),
    L(nullptr)
{
}

void LRE3ScriptSystem::Init()
{
    assert(!m_bInitialized);

    L = luaL_newstate();
    luaL_openlibs(L);

    m_bInitialized = true;
}
void LRE3ScriptSystem::Shutdown()
{
    if (L) lua_close(L);
}

bool LRE3ScriptSystem::DoString(std::string str)
{
    if (luaL_dostring(L, str.c_str()))
    {
        LUA_PRINT_ERROR(L);
        return false;
    }
    return true;
}

bool LRE3ScriptSystem::DoFile(std::string filename)
{
    if (luaL_dofile(L, filename.c_str()))
    {
        LUA_PRINT_ERROR(L);
        return false;
    }
    return true;
}

bool LRE3ScriptSystem::AddDirectoryToPath(std::string path)
{
    return DoString(format("package.path = package.path .. ';{}/?.lua'", path));
}

void LRE3ScriptSystem::PushNil()
{
    lua_pushnil(L);
}
void LRE3ScriptSystem::PushBool(bool b)
{
    lua_pushboolean(L, (int)b);
}
void LRE3ScriptSystem::PushNumber(double n)
{
    lua_pushnumber(L, n);
}
void LRE3ScriptSystem::PushString(std::string str)
{
    lua_pushstring(L, str.c_str());
}
void LRE3ScriptSystem::PushUserType(void* udata, std::string tname)
{
    lua_pushlightuserdata(L, udata);
    // luaL_getmetatable(L, tname.c_str());
    // lua_setmetatable(L, -2);
}
bool LRE3ScriptSystem::GetBool(int index)
{
    return (bool)lua_toboolean(L, index);
}
double LRE3ScriptSystem::GetNumber(int index)
{
    return lua_tonumber(L, index);
}
std::string LRE3ScriptSystem::GetString(int index)
{
    return std::string(lua_tostring(L, index));
}
void* LRE3ScriptSystem::GetUserType(int index, std::string tname)
{
    return lua_touserdata(L, index);
}
void LRE3ScriptSystem::SetGlobal(std::string name)
{
    lua_setglobal(L, name.c_str());
}

int LRE3ScriptSystem::RegisterClass(std::string classname)
{
    // luaL_newmetatable(L, classname.c_str());
    // lua_pushvalue(L, -1);
    // lua_setfield(L, -2, "__index"); // mt.__index = mt;
    return 1;
}

lua_State* LRE3ScriptSystem::GetState() const
{
    return L;
}