#pragma once

#include "lre3_object.h"
#include "lre3_texture.h"
#include "lre3_shader.h"
#include "lre3_sprite_renderer.h"
#include "lre3_engine_systems.h"

class LRE3SpriteObject : public LRE3Object
{
public:
    LRE3SpriteObject(std::string name);

    virtual void Draw();
    void SetShader(LRE3Shader* shader);
    void SetTexture(LRE3Texture* texture);

protected:
    LRE3Texture* m_pTexture;
    LRE3Shader* m_pShader;
    glm::vec4 m_color;
};