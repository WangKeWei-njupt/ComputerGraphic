#version 330 core //Æ¬¶Î×ÅÉ«Æ÷
out vec4 color;
in vec3 vertexColor;
in vec2 ourTextCoord;
uniform float time;
uniform vec4 ourColor;
void main()
{
color = vec4(vertexColor,1.0f);
color = ourColor; 
}