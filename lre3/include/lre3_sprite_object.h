#pragma once

#include "lre3_object.h"
#include "lre3_texture.h"
#include "lre3_shader.h"
#include "lre3_sprite_renderer.h"
#include "lre3_engine_subsystems.h"

#include <vector>

class LRE3SpriteObject : public LRE3Object
{
public:
    LRE3SpriteObject(std::string name);

    virtual std::shared_ptr<LRE3Object> Duplicate(std::string newName);

    virtual void Draw();
    void SetShader(LRE3Shader* shader);
    void SetTexture(LRE3Texture* texture);

    void SetTileShape(unsigned int nRows, unsigned int nCols);
    void SetTile(unsigned int i, unsigned int j, int tile) { m_tiles[j + i * m_nCols] = tile;}
    void SetTilesVec(std::vector<int> tiles) { m_tiles.clear(); for(auto x : tiles) m_tiles.push_back(x); }

    void SetFlipHorizontal(bool flip) { m_bFilpHorizontal = flip; }
    void SetFlipVertical(bool flip) { m_bFlipVertical = flip; }

protected:
    LRE3Texture* m_pTexture;
    LRE3Shader* m_pShader;
    glm::vec4 m_color;

    std::vector<int> m_tiles;
    unsigned int m_nRows, m_nCols;
    bool m_bFilpHorizontal, m_bFlipVertical;
};