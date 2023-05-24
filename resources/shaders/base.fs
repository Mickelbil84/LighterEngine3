#version 410 core

in vec2 texCoord;

uniform sampler2D textureMap;
uniform int textureRows, textureCols;
uniform int bUseTexture;

uniform int tileRow, tileCol;

uniform vec4 color;

out vec4 fragColor;

void main()
{
    vec2 uv = texCoord;
    uv.x = (uv.x + tileCol) / textureCols;
    uv.y = (uv.y + tileRow) / textureRows;

    fragColor = color;
    if (bUseTexture != 0)
        fragColor *= texture(textureMap, uv);

}