#include "lre3_engine_subsystems.h"

LRE3EngineSubsystems LRE3EngineSubsystems::g_instance;

void LRE3EngineSubsystems::InitSubsystems()
{
    m_spriteRenderer.Init();
    m_scriptSystem.Init();

    deltaTime = 0.0;
}

void LRE3EngineSubsystems::ShutdownSubsystems()
{
    m_spriteRenderer.Shutdown();
    m_scriptSystem.Shutdown();
}