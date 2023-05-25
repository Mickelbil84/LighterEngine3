#include "lre3_sprite_object.h"

LRE3SpriteObject::LRE3SpriteObject(std::string name) :
    LRE3Object(name),
    m_pTexture(nullptr),
    m_color(glm::vec4(1.f)),
    m_nRows(1), m_nCols(1),
    m_bFilpHorizontal(false), m_bFlipVertical(false)
{
    m_tiles.push_back(0);
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
    LRE3GetSpriteRenderer().DrawTextureAtlas(m_pShader, m_pTexture, m_tiles, m_nRows, m_nCols, GetModelMatrix(), m_color, GetDepth(), m_bFilpHorizontal, m_bFlipVertical);
}

void LRE3SpriteObject::SetTexture(LRE3Texture* texture)
{
    m_pTexture = texture;
}
void LRE3SpriteObject::SetShader(LRE3Shader* shader)
{
    m_pShader = shader;
}

void LRE3SpriteObject::SetTileShape(unsigned int nRows, unsigned int nCols)
{
    m_nRows = nRows; m_nCols = nCols;
    m_tiles.clear();
    for (int i = 0; i < m_nRows; i++)
    for (int j = 0; j < m_nCols; j++)
        m_tiles.push_back(-1);
}