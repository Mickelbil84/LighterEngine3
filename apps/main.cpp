#include <lre3_application.h>
#include <lre3_shader.h>
#include <lre3_sprite_renderer.h>
#include <lre3_scene_manager.h>

class LRE3Main : public LRE3Application
{
public:
    int defaultWidth, defaultHeight;

    LRE3SceneManager scene;

    LRE3Main(LRE3ApplicationSettings settings) : LRE3Application(settings)
    {
        defaultWidth = settings.windowWidth; defaultHeight = settings.windowHeight;
    }

    virtual int Init()
    {
        scene.applicationSettings = &this->m_settings;
        scene.Init();
        scene.AddCamera();
        scene.GetCamera()->SetAspectRatio((float)m_settings.windowWidth / (float)m_settings.windowHeight);

        SetSceneGlobal(&scene);
        
        LRE3GetScriptSystem().AddDirectoryToPath("resources/scripts");
        LRE3GetScriptSystem().DoFile("resources/scripts/test.lua");

        return 0;
    }

    virtual void HandleInput(LRE3Input input)
    {
        if (input.keyboard[SDL_SCANCODE_ESCAPE])
            m_bShouldRun = false;
        
        if (input.keyboard[SDL_SCANCODE_F11])
            ToggleFullscreen();
    }

    virtual void Update(double deltaTime)
    {
        scene.GetRoot()->Update(deltaTime);
    }

    virtual void Render()
    {
        scene.Render();

        LRE3GetSpriteRenderer().DrawTextureAtlas(
            scene.assets.GetShader("S_base"), scene.assets.GetTexture("T_demo_tilesheet"), 
            std::vector<unsigned int>({
                49, 50, 51, 52,
                49, 50, 51, 52,
                49, 50, 51, 52,
                49, 50, 51, 52}),
            4, 4);
    }

    virtual void Shutdown()
    {
    }

    void ToggleFullscreen()
    {
        if (m_settings.bIsFullscreen)
        {
            m_settings.windowWidth = defaultWidth;
            m_settings.windowHeight = defaultHeight;
            m_settings.bIsFullscreen = false;
        }
        else
        {
            m_settings.windowWidth = 1920;
            m_settings.windowHeight = 1080;
            m_settings.bIsFullscreen = true;
        }

        ApplyWindowSettings();
    }
};

int main()
{
    LRE3ApplicationSettings settings;
    settings.windowWidth = 1024;
    settings.windowHeight = 786;
    // settings.bWireframe = true;

    LRE3Main app(settings);
    return app.Run();
}