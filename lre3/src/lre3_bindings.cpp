#include "lre3_bindings.h"

void LRE3Bind()
{
    lua_State* L = LRE3GetScriptSystem().GetState();
    AddScancodeGlobals();

    REGISTER(LRE3Input);
    REGISTER(LRE3SceneManager);
    REGISTER(LRE3AssetManager);

    REGISTER(LRE3Texture);
    REGISTER(LRE3Shader);

    REGISTER(LRE3Object);
    REGISTER_OOP(LRE3Camera, LRE3Object);
    REGISTER_OOP(LRE3SceneRoot, LRE3Object);
    REGISTER_OOP(LRE3SpriteObject, LRE3Object);
    REGISTER_OOP(LRE3AnimatedSprite, LRE3SpriteObject);
}
