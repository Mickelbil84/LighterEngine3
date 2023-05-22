#pragma once

#include "lre3_engine_subsystems.h"

#include "lre3_shader.h"
#include "lre3_object.h"
#include "lre3_texture.h"
#include "lre3_scene_manager.h"
#include "lre3_asset_manager.h"


void LRE3Bind();

void SetSceneGlobal(LRE3SceneManager* scene);

int luaopen_LRE3Texture(lua_State* L);
int luaopen_LRE3Shader(lua_State* L);

int luaopen_LRE3AssetManager(lua_State* L);
int luaopen_LRE3SceneManager(lua_State* L);

int luaopen_LRE3Object(lua_State* L);