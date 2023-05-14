#pragma once
#include <gl/glew.h>
#include <string>

struct LRE3ApplicationSettings
{
    /////////////////////
    //  Window Settings
    /////////////////////
    std::string windowTitle = "LighterEngine3";
    int windowWidth = 800, windowHeight = 600;
    int maxFPS = 300;
    bool bIsResizable = false, bIsFullscreen = false;

    /////////////////////
    //  OpenGL Settings
    /////////////////////
    GLclampf defaultBackgroundR = 100.f/255.f;
    GLclampf defaultBackgroundG = 149.f/255.f;
    GLclampf defaultBackgroundB = 237.f/255.f;
    GLuint numSamples = 16;
    bool bEnableDepthTest = true;
    bool bWireframe = false;
};