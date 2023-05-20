#include "lre3_engine_subsystems.h"

LRE3EngineSubsystems LRE3EngineSubsystems::g_instance;

void LRE3EngineSubsystems::InitSubsystems()
{
    m_spriteRenderer.Init();
}

void LRE3EngineSubsystems::ShutdownSubsystems()
{
    m_spriteRenderer.Shutdown();
}