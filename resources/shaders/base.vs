#version 410 core

layout(location = 0) in vec2 vPosition;

out vec2 texCoord;

uniform mat3 view;
uniform mat3 projection;

uniform vec2 position;
uniform vec2 dimensions;

void main()
{
    vec3 pos = projection * view * vec3(vPosition * dimensions + position, 1.0);
    gl_Position = vec4(pos.xy, 0.0, 1.0);
    texCoord = vPosition;
}
