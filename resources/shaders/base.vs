#version 410 core

layout(location = 0) in vec2 vPosition;

out vec2 texCoord;

uniform vec2 position;
uniform vec2 dimensions;

void main()
{
    gl_Position = vec4(vPosition * dimensions + position, 0.0, 1.0);
    texCoord = vPosition;
}
