#pragma once

#include <gl/glew.h>

#include "lre3_shader.h"

class LRE3SpriteRenderer
{
public:
    static void Init();

    static void DrawSolidColor(LRE3Shader& shader, glm::vec2 position=glm::vec2(0.f), glm::vec2 dimensions=glm::vec2(1.f));

private:
    LRE3SpriteRenderer() {}

    // Rectangle data
    static GLuint m_spriteVAO, m_spriteVBO, m_spriteIBO;
};