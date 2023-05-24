#pragma once

#include <gl/glew.h>

#include "lre3_shader.h"
#include "lre3_texture.h"

#include <vector>


class LRE3SpriteRenderer
{
public:
    LRE3SpriteRenderer();
    void Init();
    void Shutdown();

    void DrawTextureSprite(LRE3Shader* shader, LRE3Texture* texture,
        glm::mat3 modelMatrix=glm::mat3(1.f), glm::vec4 color=glm::vec4(1.f), float depth=0.f);
    
    void DrawTextureAtlas(LRE3Shader* shader, LRE3Texture* texture, 
        std::vector<unsigned int> tiles, unsigned int nRows, unsigned int nCols,
        glm::mat3 modelMatrix=glm::mat3(1.f), glm::vec4 color=glm::vec4(1.f), float depth=0.f
    );

private:
    // Rectangle data
    GLuint m_spriteVAO, m_spriteVBO, m_spriteIBO;
    bool m_bInitialized;
};