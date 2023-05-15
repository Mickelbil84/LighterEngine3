#pragma once

#include <gl/glew.h>

#include "lre3_shader.h"
#include "lre3_texture.h"

class LRE3SpriteRenderer
{
public:
    static void Init();

    static void DrawSolidColor(LRE3Shader* shader, 
        glm::vec2 position=glm::vec2(0.f), glm::vec2 dimensions=glm::vec2(1.f), 
        glm::vec4 color=glm::vec4(1.f));

    static void DrawTextureSprite(LRE3Shader* shader, LRE3Texture* texture,
        glm::vec2 position=glm::vec2(0.f), glm::vec2 dimensions=glm::vec2(1.f), 
        glm::vec4 color=glm::vec4(1.f));

private:
    LRE3SpriteRenderer() {}

    // Rectangle data
    static GLuint m_spriteVAO, m_spriteVBO, m_spriteIBO;
};