#include "lre3_sprite_renderer.h"

GLuint LRE3SpriteRenderer::m_spriteVAO = 0;
GLuint LRE3SpriteRenderer::m_spriteVBO = 0;
GLuint LRE3SpriteRenderer::m_spriteIBO = 0;

void LRE3SpriteRenderer::Init()
{
    GLfloat data[] = {
        0.f, 0.f,
        0.f, 1.f,
        1.f, 1.f, 
        1.f, 0.f
    };
    GLubyte indices[] = {
        0, 1, 2,
        0, 2, 3,
    };

    glGenVertexArrays(1, &m_spriteVAO);
    glBindVertexArray(m_spriteVAO);

    glGenBuffers(1, &m_spriteVBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_spriteVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), reinterpret_cast<void*>(data), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);

    glGenBuffers(1, &m_spriteIBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_spriteIBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), reinterpret_cast<void*>(indices), GL_STATIC_DRAW);
}

void LRE3SpriteRenderer::DrawSolidColor(LRE3Shader* shader, glm::vec2 position, glm::vec2 dimensions)
{
    shader->Use();
    shader->Uniform("position", position);
    shader->Uniform("dimensions", dimensions);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, NULL);
}