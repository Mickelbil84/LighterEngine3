#pragma once

#include <string>
#include <gl/glew.h>

class LRE3Texture
{
public:
    void Load(std::string filePath, unsigned int nRows = 1, unsigned int nCols = 1);
    void Use(GLuint activeTexture = 0);
    void Delete();

    GLuint GetTextureID() const;

    void SetName(std::string name);
    std::string GetName() const;

    void SetAtlasSize(int nRows, int nCols) { m_nRows = nRows; m_nCols = nCols; }
    unsigned int GetAtlasRows() const { return m_nRows; }
    unsigned int GetAtlasCols() const { return m_nCols; }

private:
    static unsigned char* LoadXPM(std::string xpmStr, int* x, int* y, int* n);

    GLuint m_texture;
    std::string m_name;
    unsigned int m_nRows, m_nCols;
};