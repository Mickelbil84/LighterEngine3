#include "lre3_engine_systems.h"

LRE3EngineSystems LRE3EngineSystems::g_instance;

void LRE3EngineSystems::InitSubsystems()
{
    m_spriteRenderer.Init();
}

void LRE3EngineSystems::ShutdownSubsystems()
{
    m_spriteRenderer.Shutdown();
}