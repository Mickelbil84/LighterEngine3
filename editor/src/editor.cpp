#include "editor.h"
#include "wx/wx.h"

LRE3Editor::LRE3Editor() :
    scenePath(""),
    bPauseEngine(false),
    bPauseUpdate(false)
{
}

void LRE3Editor::Init()
{
    LRE3EngineSubsystems::Instance().InitSubsystems();
    LRE3Bind();


    scene.Init();
    scene.AddCamera();
    SetSceneGlobal(&scene);

    LRE3GetScriptSystem().AddDirectoryToPath("resources/scripts");
    LRE3GetScriptSystem().DoFile("resources/scripts/test.lua");
}

void LRE3Editor::Update(float deltaTime)
{
    if (bPauseEngine || bPauseUpdate)
        return;

    scene.GetRoot()->Update(deltaTime);
}

void LRE3Editor::HandleInput(LRE3EditorInput input)
{
    if (bPauseEngine || bPauseUpdate)
        return;
    
    m_lastInput = input;
}

void LRE3Editor::Render(int width, int height)
{
    if (bPauseEngine)
        return;

    scene.GetCamera()->SetAspectRatio((float)width / (float)height);
    scene.Render(width, height);
}