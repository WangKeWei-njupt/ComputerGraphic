#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 ourColor;
layout(location = 2) in vec3 normal;
//layout(location = 2) in vec2 textCoord;
out vec3 vertexColor;
out vec3 Normal;
out vec3 FragPos;
uniform mat4 transform;
//out vec2 ourTextCoord;
uniform mat4 projection;
uniform mat4 view;
void main()
{
gl_Position =projection *view* transform * vec4(position ,1.0f);
FragPos=vec3(transform*vec4(position,1.0f));
vertexColor = ourColor;
Normal =mat3(transpose(inverse(transform)))*normal;
//ourTextCoord = vec2(textCoord.x,1-textCoord.y);
}