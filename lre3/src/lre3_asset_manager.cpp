#include "lre3_asset_manager.h"

LRE3TexturePath::LRE3TexturePath() :
    path(""),
    bIsLoaded(false)
{
}

LRE3ShaderPath::LRE3ShaderPath() :
    vertexShaderPath(""),
    fragmentShaderPath(""),
    bIsLoaded(false)
{
}

void LRE3AssetManager::Clear()
{
    m_texturesPaths.clear();
    m_shadersPaths.clear();

    m_shaders.clear();
    m_textures.clear();
}

void LRE3AssetManager::AddTexturePath(std::string name, std::string texturePath, unsigned int nRows, unsigned int nCols)
{
    LRE3TexturePath ap;
    ap.path = texturePath;
    ap.nRows =nRows; ap.nCols = nCols;
    ap.bIsLoaded = false;
    m_texturesPaths[name] = ap;
}
void LRE3AssetManager::LoadTexture(std::string name, std::string texturePath, unsigned int nRows, unsigned int nCols)
{
    LRE3Texture texture;
    texture.Load(texturePath, nRows, nCols);
    texture.SetName(name);
    m_textures[name] = texture;
    AddTexturePath(name, texturePath, nRows, nCols);
    m_texturesPaths[name].bIsLoaded = true;
}
LRE3Texture* LRE3AssetManager::GetTexture(std::string name)
{
    if (!name.size())
        return nullptr;
    LRE3TexturePath& ap = m_texturesPaths[name];
    if (!ap.bIsLoaded)
    {
        LoadTexture(name, ap.path);
        ap.bIsLoaded = true;
    }

    return &m_textures[name];
}
void LRE3AssetManager::SetTextureAtlasSize(std::string name, unsigned int nRows, unsigned int nCols)
{
    LRE3TexturePath& ap = m_texturesPaths[name];
    ap.nRows = nRows; ap.nCols = nCols;
    m_textures[name].SetAtlasSize(nRows, nCols);
}

void LRE3AssetManager::AddShaderPath(std::string name, std::string vertexShaderPath, std::string fragmentShaderPath)
{
    LRE3ShaderPath sp;
    sp.vertexShaderPath = vertexShaderPath;
    sp.fragmentShaderPath = fragmentShaderPath;
    sp.bIsLoaded = false;
    m_shadersPaths[name] = sp;
}
void LRE3AssetManager::LoadShader(std::string name, std::string vertexShaderPath, std::string fragmentShaderPath)
{
    LRE3Shader shader;
    shader.CompileShader(vertexShaderPath, fragmentShaderPath);
    shader.SetName(name);
    m_shaders[name] = shader;
    AddShaderPath(name, vertexShaderPath, fragmentShaderPath);
    m_shadersPaths[name].bIsLoaded = true;
}
LRE3Shader* LRE3AssetManager::GetShader(std::string name)
{
    LRE3ShaderPath& sp = m_shadersPaths[name];
    if (!sp.bIsLoaded)
    {
        LoadShader(name, sp.vertexShaderPath, sp.fragmentShaderPath);
        sp.bIsLoaded = true;
    }

    return &m_shaders[name];
}