#pragma once

#include "lre3_binding_macros.h"
#include "lre3_scene_manager.h"

void SetSceneGlobal(LRE3SceneManager* scene);
int luaopen_LRE3SceneManager(lua_State* L);