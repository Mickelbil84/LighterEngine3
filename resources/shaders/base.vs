#version 410 core

layout(location = 0) in vec2 vPosition;

out vec2 texCoord;

uniform mat3 model;
uniform mat3 view;
uniform mat3 projection;

uniform int deltaRow, deltaCol;
uniform int spriteRows, spriteCols;

uniform vec2 position;
uniform vec2 dimensions;
uniform float depth;

void main()
{
    vec2 deltaPos = vPosition;
    deltaPos.x = (deltaPos.x + deltaCol) / spriteCols;
    deltaPos.y = (deltaPos.y + deltaRow) / spriteRows;
    vec3 pos = projection * view * model * vec3(deltaPos, 1.0);
    gl_Position = vec4(pos.xy, (-depth - 1.0) / 2.0, 1.0);
    texCoord = vPosition;
    texCoord.y = 1 - texCoord.y;
}
