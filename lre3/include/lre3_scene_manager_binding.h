#pragma once

#include "lre3_scene_manager.h"
#include "lre3_engine_subsystems.h"

void SetSceneGlobal(LRE3SceneManager* scene);

int luaopen_LRE3SceneManager(lua_State* L);