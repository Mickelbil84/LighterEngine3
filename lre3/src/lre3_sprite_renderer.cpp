#include "lre3_sprite_renderer.h"

LRE3SpriteRenderer::LRE3SpriteRenderer() :
    m_bInitialized(false),
    m_spriteVAO(0),
    m_spriteVBO(0),
    m_spriteIBO(0)
{
}

void LRE3SpriteRenderer::Init()
{
    // We shouls initialize only once
    assert(!m_bInitialized);

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

    m_bInitialized = true;
}

void LRE3SpriteRenderer::Shutdown()
{
    if (m_spriteIBO) glDeleteBuffers(1, &m_spriteIBO);
    if (m_spriteVBO) glDeleteBuffers(1, &m_spriteVBO);
    if (m_spriteVAO) glDeleteVertexArrays(1, &m_spriteVAO);
    m_spriteIBO = m_spriteVBO = m_spriteVAO = 0;
}

void LRE3SpriteRenderer::DrawTextureSprite(LRE3Shader* shader, LRE3Texture* texture, glm::mat3 modelMatrix, glm::vec4 color, float depth)
{
    shader->Use();
    shader->Uniform("model", modelMatrix);

    if (texture)
        texture->Use();
    shader->Uniform("bUseTexture", (GLuint)(texture != nullptr));
    shader->Uniform("textureMap", (GLuint)0);
    shader->Uniform("textureRows", (GLuint)1);
    shader->Uniform("textureCols", (GLuint)1);
    shader->Uniform("tileRow", (GLuint)0);
    shader->Uniform("tileCol", (GLuint)0);
    shader->Uniform("deltaRow", (GLuint)0);
    shader->Uniform("deltaCol", (GLuint)0);
    shader->Uniform("spriteRows", (GLuint)1);
    shader->Uniform("spriteCols", (GLuint)1);
    shader->Uniform("color", color);
    shader->Uniform("depth", depth);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, NULL);
}

void LRE3SpriteRenderer::DrawTextureAtlas(LRE3Shader* shader, LRE3Texture* texture, 
        std::vector<unsigned int> tiles, unsigned int nRows, unsigned int nCols,
        glm::mat3 modelMatrix, glm::vec4 color, float depth)
{
    shader->Use();
    shader->Uniform("model", modelMatrix);

    if (texture)
        texture->Use();
    shader->Uniform("bUseTexture", (GLuint)(texture != nullptr));
    shader->Uniform("textureMap", (GLuint)0);
    shader->Uniform("textureRows", (GLuint)texture->GetAtlasRows());
    shader->Uniform("textureCols", (GLuint)texture->GetAtlasCols());
    shader->Uniform("spriteRows", (GLuint)nRows);
    shader->Uniform("spriteCols", (GLuint)nCols);
    shader->Uniform("color", color);
    shader->Uniform("depth", depth);

    for (int i = 0; i < nRows; i++)
    for (int j = 0; j < nCols; j++)
    {
        unsigned int tile = tiles[j + i * nRows];
        shader->Uniform("tileRow", tile / (GLuint)texture->GetAtlasCols());
        shader->Uniform("tileCol", tile % (GLuint)texture->GetAtlasCols());
        shader->Uniform("deltaRow", (GLuint)i);
        shader->Uniform("deltaCol", (GLuint)j);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, NULL);
    }
    
}