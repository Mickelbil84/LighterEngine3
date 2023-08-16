#pragma once

#include <map>
#include <math.h>

#include <lre3_bindings.h>
#include <lre3_scene_manager.h>

#include "editor_input.h"

class LRE3Editor
{
public:
    LRE3EditorInput m_lastInput;

public:
    LRE3Editor();

    LRE3SceneManager scene;
    std::string scenePath;
    int paneWidth, paneHeight;
    bool bPauseEngine, bPauseUpdate;

public:
    void Init();
    void Update(float deltaTime);
    void HandleInput(LRE3EditorInput input);
    void Render(int width, int height);  
};