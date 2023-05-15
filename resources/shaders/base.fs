#version 410 core

in vec2 texCoord;

uniform sampler2D textureMap;
uniform int bUseTexture;
uniform vec4 color;

out vec4 fragColor;

void main()
{
    vec2 uv = texCoord;
    // TODO: Handle sprite sheet

    fragColor = color;
    if (bUseTexture != 0)
        fragColor *= texture(textureMap, uv);

}