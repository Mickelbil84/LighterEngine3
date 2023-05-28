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
    if ((tileCol < 0) || (tileRow < 0)) discard;

    ivec2 texSize = textureSize(textureMap, 0);
    float tileSizeX = float(texSize.x) / textureCols;
    float tileSizeY = float(texSize.y) / textureRows;

    float left_x = tileCol * tileSizeX + 1;
    float right_x = (tileCol + 1) * tileSizeX - 1;

    float left_y = tileRow * tileSizeY + 1; 
    float right_y = (tileRow + 1) * tileSizeY - 1;

    uv.x = mix(left_x, right_x, uv.x) / texSize.x;
    uv.y = mix(left_y, right_y, uv.y) / texSize.y;

    fragColor = color;
    if (bUseTexture != 0)
        fragColor *= texture(textureMap, uv);

}