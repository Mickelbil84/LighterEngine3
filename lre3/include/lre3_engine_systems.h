#pragma once 

#include "lre3_sprite_renderer.h"

class LRE3EngineSystems
{
public:
    static LRE3EngineSystems& Instance() { return g_instance; }

    void InitSubsystems();
    void ShutdownSubsystems();

    LRE3SpriteRenderer& GetSpriteRenderer() { return m_spriteRenderer; }

private:
    LRE3EngineSystems() {}
    static LRE3EngineSystems g_instance;

    // Subsystems
    LRE3SpriteRenderer m_spriteRenderer;
};