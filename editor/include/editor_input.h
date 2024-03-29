#pragma once

#include <map>

struct LRE3EditorInput
{
    std::map<int, bool> keyboard;
	int xrel, yrel;
    int mouseX, mouseY;
    int screenWidth, screenHeight;
    float relativeMouseX, relativeMouseY;
    bool bLeftMouse, bRightMouse;
};