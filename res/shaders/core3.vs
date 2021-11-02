#version 330 core  //������ɫ���汾
layout(location = 0) in vec3 position;   //���Դ����ȡ����ӳ�䵽position
layout(location = 1) in vec3 ourColor;   //��ȡ��ɫ
layout(location = 2) in vec3 normal;     //��ȡ������

out vec3 vertexColor; //����Ƭ����ɫ��
out vec3 Normal;
out vec3 FragPos; //�۲��λ��
uniform mat4 transform;
uniform mat4 projection;
uniform mat4 view;
void main()
{
    gl_Position = projection * view * transform * vec4(position, 1.0f);  //���ն�����Ϣ��ά����
    FragPos = vec3(transform*vec4(position,1.0f));
    vertexColor = ourColor;
    Normal = mat3(transpose(inverse(transform)))*normal;
}