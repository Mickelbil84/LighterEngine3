#pragma once 

#include "lre3_sprite_renderer.h"
#include "lre3_script_system.h"

class LRE3EngineSubsystems
{
public:
    static LRE3EngineSubsystems& Instance() { return g_instance; }

    void InitSubsystems();
    void ShutdownSubsystems();

    LRE3SpriteRenderer& GetSpriteRenderer() { return m_spriteRenderer; }
    LRE3ScriptSystem& GetScriptSystem() { return m_scriptSystem; }

private:
    LRE3EngineSubsystems() {}
    static LRE3EngineSubsystems g_instance;

    // Subsystems
    LRE3SpriteRenderer m_spriteRenderer;
    LRE3ScriptSystem m_scriptSystem;
};

#define GetEngine LRE3EngineSubsystems::Instance
#define LRE3GetSpriteRenderer LRE3EngineSubsystems::Instance().GetSpriteRenderer
#define LRE3GetScriptSystem LRE3EngineSubsystems::Instance().GetScriptSystem