#include "lre3_bindings.h"


FBIND(LRE3AssetManager, LoadTexture)
{
    GET_SELF(LRE3AssetManager);
    GET_STRING(name, 2);
    GET_STRING(path, 3);
    self->LoadTexture(name, path);
    return 0;
}
FBIND(LRE3AssetManager, GetTexture)
{
    GET_SELF(LRE3AssetManager);
    GET_STRING(name, 2);
    PUSH_UDATA(self->GetTexture(name), LRE3Texture);
    return 1;
}
FBIND(LRE3AssetManager, SetTextureAtlasSize)
{
    GET_SELF(LRE3AssetManager);
    std::string textureName;
    if (lua_isstring(LRE3GetScriptSystem().GetState(), 2))
    {
        GET_STRING(tmp, 2);
        textureName = tmp;
    }
    else
    {
        GET_UDATA(texture, LRE3Texture, 2);
        textureName = texture->GetName();
    }
    GET_NUMBER(nRows, 3);
    GET_NUMBER(nCols, 4);
    self->SetTextureAtlasSize(textureName, nRows, nCols);
    return 0;
}
FBIND(LRE3AssetManager, LoadShader)
{
    GET_SELF(LRE3AssetManager);
    GET_STRING(name, 2);
    GET_STRING(vs_path, 3);
    GET_STRING(fs_path, 4);
    self->LoadShader(name, vs_path, fs_path);
    return 0;
}
FBIND(LRE3AssetManager, GetShader)
{
    GET_SELF(LRE3AssetManager);
    GET_STRING(name, 2);
    PUSH_UDATA(self->GetShader(name), LRE3Shader);
    return 1;
}

LIB(LRE3AssetManager) = {
    {"load_texture", FNAME(LRE3AssetManager, LoadTexture)},
    {"get_texture", FNAME(LRE3AssetManager, GetTexture)},
    {"set_texture_atlas_size", FNAME(LRE3AssetManager, SetTextureAtlasSize)},
    {"load_shader", FNAME(LRE3AssetManager, LoadShader)},
    {"get_shader", FNAME(LRE3AssetManager, GetShader)},
    {NULL, NULL}
};

LOPEN(LRE3AssetManager);