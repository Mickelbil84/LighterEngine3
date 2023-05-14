#include <lre3_application.h>
#include <lre3_shader.h>
#include <lre3_sprite_renderer.h>

class LRE3Main : public LRE3Application
{
public:
    int defaultWidth, defaultHeight;

    LRE3Shader shader;
    LRE3SpriteRenderer spriteRenderer;



    LRE3Main(LRE3ApplicationSettings settings) : LRE3Application(settings)
    {
        defaultWidth = settings.windowWidth; defaultHeight = settings.windowHeight;
    }

    virtual int Init()
    {
        shader.CompileShader("resources/shaders/base.vs", "resources/shaders/base.fs");
        spriteRenderer.Init();

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
    }

    virtual void Render()
    {
        spriteRenderer.DrawSolidColor(shader, glm::vec2(-.5f), glm::vec2(0.5f));
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