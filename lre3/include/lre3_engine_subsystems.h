#pragma once 

#include "lre3_sprite_renderer.h"

class LRE3EngineSubsystems
{
public:
    static LRE3EngineSubsystems& Instance() { return g_instance; }

    void InitSubsystems();
    void ShutdownSubsystems();

    LRE3SpriteRenderer& GetSpriteRenderer() { return m_spriteRenderer; }

private:
    LRE3EngineSubsystems() {}
    static LRE3EngineSubsystems g_instance;

    // Subsystems
    LRE3SpriteRenderer m_spriteRenderer;
};