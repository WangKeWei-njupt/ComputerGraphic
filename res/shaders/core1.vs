#version 330 core  //������ɫ���汾
layout(location = 0) in vec3 position;   //���Դ����ȡ����ӳ�䵽position
layout(location = 1) in vec3 ourColor;   //��ȡ��ɫ

out vec3 vertexColor; //����Ƭ����ɫ��
out vec2 ourTextCoord;
void main()
{
    gl_Position = vec4(position, 1.0f);  //���ն�����Ϣ��ά����
    vertexColor = ourColor;
}