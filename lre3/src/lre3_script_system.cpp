#include "lre3_script_system.h"

#include "lre3_engine_subsystems.h"

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

    // Set pointer binding table
    // lua_newtable(L);
    // lua_setglobal(L, LUA_BINDING_TABLE);

    m_bInitialized = true;
    scriptObserver.SetState(L);
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
    if (!udata)
    {
        lua_pushnil(L);
        return;
    }

    lua_pushlightuserdata(L, udata);
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_isnil(L, -1))
    {
        // Create new table with the light userdata inside _ptr
        lua_newtable(L);
        lua_pushlightuserdata(L, udata);
        lua_setfield(L, -2, "_ptr");

        // Attach the correct metatable
        luaL_getmetatable(L, tname.c_str());
        lua_setmetatable(L, -2);

        // Register the table pointer
        lua_pushlightuserdata(L, udata);
        lua_pushvalue(L, -2);
        lua_rawset(L, LUA_REGISTRYINDEX);
    }
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
std::string LRE3ScriptSystem::GetStringOrNil(int index)
{
    if (lua_isstring(L, index)) return GetString(index);
    return std::string("");
}
int LRE3ScriptSystem::CheckUserType(void* udata, std::string tname)
{
    // lua_getfield(L, LUA_REGISTRYINDEX, tname.c_str());
    // lua_getmetatable(L, )
    return 0;
}
void* LRE3ScriptSystem::GetUserType(int index, std::string tname, std::string* actual_tname)
{
    lua_getfield(L, LUA_REGISTRYINDEX, tname.c_str());

    // Figure out the actual name
    if (actual_tname)
    {
        int res = luaL_getmetafield(L, index, "__name");
        (*actual_tname) = GetString(-1);
        lua_pop(L, 1);
    }

    lua_getmetatable(L, index);
    while (lua_istable(L, -1))
    {
        if (lua_rawequal(L, -1, -2))
        {
            lua_pop(L, 2);
            lua_getfield(L, index, "_ptr");
            void* udata = lua_touserdata(L, -1);
            return udata;
        }
        lua_getfield(L, -1, "_base");
        lua_replace(L, -2);
    }
    luaL_typeerror(L, index, tname.c_str());
    return nullptr;
}
void LRE3ScriptSystem::SetGlobal(std::string name)
{
    lua_setglobal(L, name.c_str());
}

int LRE3ScriptSystem::RegisterClass(std::string classname, std::string baseclass)
{
    // We assume that the lib table is on top of the stack
    luaL_newmetatable(L, classname.c_str());
    lua_pushvalue(L, -2); 
    lua_setfield(L, -2, "__index"); // mt.__index = libtable
    if (baseclass != "")
    {
        luaL_getmetatable(L, baseclass.c_str());
        lua_setfield(L, -2, "_base"); // mt._base = base metatable
    }
    lua_pop(L, 1); // Pop the metatable
    if (baseclass != "")
    {
        lua_getglobal(L, baseclass.c_str());
        lua_setfield(L, -2, "__index"); // libtable.__index = base libtable
        lua_pushvalue(L, -1);
        lua_setmetatable(L, -2);
    }
    return 1; 
}

lua_State* LRE3ScriptSystem::GetState() const
{
    return L;
}

void LRE3ScriptSystem::ReleaseUserType(void* udata)
{
    // lua_getglobal(L, LUA_BINDING_TABLE);
    lua_pushlightuserdata(L, udata);
    lua_pushnil(L);
    lua_settable(L, LUA_REGISTRYINDEX);
    // lua_pop(L, 1);
}

void LRE3ScriptObserver::SetState(lua_State* L)
{
    this->L = L;
}

void LRE3ScriptObserver::OnNotify(LRE3Object* sender, LRE3EventType eventType)
{
    switch(eventType)
    {
    case LRE3_EVENT_OBJECT_UPDATE:
        // Check if the sender has an 'update' method
        lua_pushlightuserdata(L, (void*)sender);
        lua_gettable(L, LUA_REGISTRYINDEX); // now -1 is the Lua object table
        lua_getfield(L, -1, "update");
        if (lua_isfunction(L, -1)) // -1 is function, -2 is obj
        {
            lua_pushvalue(L, -2); // -1 is obj, -2 is function
            lua_pushnumber(L, LRE3EngineSubsystems::Instance().deltaTime); // -1 is deltaTime, -2 is obj, -3 is function
            lua_call(L, 2, 0);
            lua_pop(L, 1);
        }
        else
            lua_pop(L, 2);
        break;

    default:
        break;
    }
}