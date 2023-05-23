#version 410 core

layout(location = 0) in vec2 vPosition;

out vec2 texCoord;

uniform mat3 model;
uniform mat3 view;
uniform mat3 projection;

uniform vec2 position;
uniform vec2 dimensions;
uniform float depth;

void main()
{
    vec3 pos = projection * view * model * vec3(vPosition, 1.0);
    gl_Position = vec4(pos.xy, (-depth - 1.0) / 2.0, 1.0);
    texCoord = vPosition;
    texCoord.y = 1 - texCoord.y;
}
