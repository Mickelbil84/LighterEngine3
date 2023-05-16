#pragma once

#include <gl/glew.h>

#include "lre3_shader.h"
#include "lre3_texture.h"

class LRE3SpriteRenderer
{
public:
    static void Init();

    static void DrawTextureSprite(LRE3Shader* shader, LRE3Texture* texture,
        glm::mat3 modelMatrix=glm::mat3(1.f), glm::vec4 color=glm::vec4(1.f));

private:
    LRE3SpriteRenderer() {}

    // Rectangle data
    static GLuint m_spriteVAO, m_spriteVBO, m_spriteIBO;
};