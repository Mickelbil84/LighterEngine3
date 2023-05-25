#include "lre3_bindings.h"


FBIND(LRE3SpriteObject, SetShader)
{   
    GET_SELF(LRE3SpriteObject);
    GET_UDATA(shader, LRE3Shader, 2);
    self->SetShader(shader);
    return 0;
}

FBIND(LRE3SpriteObject, SetTexture)
{
    GET_SELF(LRE3SpriteObject);
    GET_UDATA(texture, LRE3Texture, 2);
    self->SetTexture(texture);
    return 0;
}

FBIND(LRE3SpriteObject, SetTileShape)
{
    GET_SELF(LRE3SpriteObject);
    GET_NUMBER(nRows, 2);
    GET_NUMBER(nCols, 3);
    self->SetTileShape((unsigned int)nRows, (unsigned int)nCols);
    return 0;
}

FBIND(LRE3SpriteObject, SetTile)
{
    GET_SELF(LRE3SpriteObject);
    GET_NUMBER(i, 2);
    GET_NUMBER(j, 3);
    GET_NUMBER(tile, 4);
    self->SetTile((unsigned int)i, (unsigned int)j, (int)tile);
    return 0;
}

FBIND(LRE3SpriteObject, SetFlipHorizontal)
{
    GET_SELF(LRE3SpriteObject);
    GET_BOOL(flip, 2);
    self->SetFlipHorizontal(flip);
    return 0;
}

FBIND(LRE3SpriteObject, SetFlipVertical)
{
    GET_SELF(LRE3SpriteObject);
    GET_BOOL(flip, 2);
    self->SetFlipVertical(flip);
    return 0;
}

FBIND(LRE3SpriteObject, SetTilesFromTable)
{
    GET_SELF(LRE3SpriteObject);
    GET_NUMBER(nRows, 2);
    GET_NUMBER(nCols, 3);

    PUSH_NIL();
    std::vector<int> tiles;
    while(lua_next(LRE3GetScriptSystem().GetState(), 4))
    {
        if (lua_isnumber(LRE3GetScriptSystem().GetState(), -1))
            tiles.push_back(LRE3GetScriptSystem().GetNumber(-1));
        lua_pop(LRE3GetScriptSystem().GetState(), 1);
        // std::cout << lua_gettop(LRE3GetScriptSystem().GetState()) << std::endl;
    }
    self->SetTileShape(nRows, nCols);
    self->SetTilesVec(tiles);
    return 0;
}

LIB(LRE3SpriteObject) = {
    {"set_shader", FNAME(LRE3SpriteObject, SetShader)},
    {"set_texture", FNAME(LRE3SpriteObject, SetTexture)},

    {"set_tile_shape", FNAME(LRE3SpriteObject, SetTileShape)},
    {"set_tile", FNAME(LRE3SpriteObject, SetTile)},
    {"set_tiles_from_table", FNAME(LRE3SpriteObject, SetTilesFromTable)},

    {"set_flip_horizontal", FNAME(LRE3SpriteObject, SetFlipHorizontal)},
    {"set_flip_vertical", FNAME(LRE3SpriteObject, SetFlipVertical)},
    {NULL, NULL}
};
LOPEN(LRE3SpriteObject)