#include "lre3_sprite_object.h"

LRE3SpriteObject::LRE3SpriteObject(std::string name) :
    LRE3Object(name),
    m_pTexture(nullptr),
    m_color(glm::vec4(1.f))
{
}

void LRE3SpriteObject::Draw()
{
    LRE3EngineSystems::Instance().GetSpriteRenderer().DrawTextureSprite(m_pShader, m_pTexture, GetModelMatrix(), m_color);
}

void LRE3SpriteObject::SetTexture(LRE3Texture* texture)
{
    m_pTexture = texture;
}
void LRE3SpriteObject::SetShader(LRE3Shader* shader)
{
    m_pShader = shader;
}