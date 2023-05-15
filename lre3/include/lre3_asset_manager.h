#pragma once

#include <map>
#include <string>

#include <cereal/cereal.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/string.hpp>

#include "lre3_utils.h"
#include "lre3_shader.h"
#include "lre3_texture.h"


struct LRE3AssetPath
{
    LRE3AssetPath();

    std::string path;
    bool bIsLoaded;

    template <class Archive>
    void serialize(Archive & ar)
    {
        ar(CEREAL_NVP(path));
    }
};

struct LRE3ShaderPath
{
    LRE3ShaderPath();

    std::string vertexShaderPath, fragmentShaderPath;
    bool bIsLoaded;

    template <class Archive>
    void serialize(Archive & ar)
    {
        ar(CEREAL_NVP(vertexShaderPath));
        ar(CEREAL_NVP(fragmentShaderPath));
    }
};


class LRE3AssetManager
{
public:
    void Clear();

    void AddTexturePath(std::string name, std::string texturePath);
    void LoadTexture(std::string name, std::string texturePath);
    LRE3Texture* GetTexture(std::string name);

    void AddShaderPath(std::string name, std::string vertexShaderPath, std::string fragmentShaderPath);
    void LoadShader(std::string name, std::string vertexShaderPath, std::string fragmentShaderPath);
    LRE3Shader* GetShader(std::string name);

    /*
    *  Textures and shaders can also be added lazily, and loaded on demand
    */
    std::map<std::string, LRE3AssetPath> m_texturesPaths;
    std::map<std::string, LRE3ShaderPath> m_shadersPaths;

    std::map<std::string, LRE3Shader> m_shaders;
    std::map<std::string, LRE3Texture> m_textures;

    template <class Archive>
    void save( Archive & ar ) const
    {
        ar(CEREAL_NVP(m_texturesPaths));
        ar(CEREAL_NVP(m_shadersPaths));
    }

    template <class Archive>
    void load( Archive & ar )
    {
        ar(m_texturesPaths);
        ar(m_shadersPaths);
    }
};