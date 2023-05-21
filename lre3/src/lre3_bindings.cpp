#include "lre3_bindings.h"

void LRE3Bind()
{
    luaopen_LRE3SceneManager(LRE3GetScriptSystem().GetState());
}