#include "lre3_sprite_object.h"

LRE3SpriteObject::LRE3SpriteObject(std::string name) :
    LRE3Object(name),
    m_pTexture(nullptr),
    m_color(glm::vec4(1.f))
{
}

std::shared_ptr<LRE3Object> LRE3SpriteObject::Duplicate(std::string newName)
{
    std::shared_ptr<LRE3SpriteObject> newCopy(new LRE3SpriteObject(newName));
    newCopy->CopyDataFromOther(this);
    newCopy->SetTexture(this->m_pTexture);
    newCopy->SetShader(this->m_pShader);
    return std::dynamic_pointer_cast<LRE3Object>(newCopy);
}

void LRE3SpriteObject::Draw()
{
    LRE3EngineSubsystems::Instance().GetSpriteRenderer().DrawTextureSprite(m_pShader, m_pTexture, GetModelMatrix(), m_color, m_depth);
}

void LRE3SpriteObject::SetTexture(LRE3Texture* texture)
{
    m_pTexture = texture;
}
void LRE3SpriteObject::SetShader(LRE3Shader* shader)
{
    m_pShader = shader;
}