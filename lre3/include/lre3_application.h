#pragma once
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <gl/glew.h>
#include <iostream>

#include "lre3_application_settings.h"
#include "lre3_input.h"
#include "lre3_engine_subsystems.h"
// #include "LRE3_physics.h"

// Base abstract class for any LRE3 based application.
// User should implement all abstract functions (they may be empty).
// Usage:
//      class AppName : public LRE3Application
//      {
//          AppName(LRE3ApplicationSettings settings) : LRE3Application(settings) {}
//
//          ... // Override all other functionality
//
//      }
//      
//      int main(int argc, char** argv)
//      {
//          LRE3ApplicationSettings settings;
//          AppName app(settings);
//          return app.Run();
//      }
class LRE3Application
{
public:
    LRE3Application(LRE3ApplicationSettings settings);

    // Initialized all user data. Called only once, at the beginning of the program.
    virtual int Init() = 0;
    // Handles the input (or any other event). Runs each frame, if some user event occured.
    virtual void HandleInput(LRE3Input input) = 0;
    // Updates the application/game state. Runs each frame. The argument `deltaTime` is
    // the time (in seconds) that took to process the last frame and can be used to update/move entities 
    // in a speed that is independant from the running speed of the application.
    virtual void Update(double deltaTime) = 0;
    // Renders objects to screen. Runs each frame.
    virtual void Render() = 0;
    // Frees any alocated memory and any other processing that is needed
    // at the end of the application. Runs only once, at the end of the program.
    virtual void Shutdown() = 0;

    // Initialized, runs and cleans the program. This is the only method of the application
    // that the user should call.
    int Run();
protected:
    bool m_bShouldRun;
    double m_deltaTime;
    LRE3ApplicationSettings m_settings;

    LRE3Input m_lastInput;

    // Updates only the title of the window (and also in the settings)
    // This is seperate from `ApplyWindowSettings` since this might be called
    // once in a few frames, and we don't want to change the size of the window
    // and other settings so often.
    void UpdateWindowTitle(std::string windowTitle);
    // Applies all window settings. This should be called if
    // the window settings in the LRE3ApplicationSettings were modified.
    void ApplyWindowSettings();
    // Applies all OpenGL settings.
    void ApplyOpenGLSettings();

private:
    // Initialized internal structures of the application.
    int _Init();
    // Runs the game loop of the application.
    int _Run();
    // Frees internal structures of the application.
    void _Shutdown();

    SDL_Window* m_pWindow;
    SDL_GLContext m_glcontext;
};