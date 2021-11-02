#version 330 core //Ƭ����ɫ��
out vec4 color;
in vec3 vertexColor;
in vec3 Normal;
in vec3 FragPos;
uniform vec3 LightPos; //��������ϵ�¹�Դλ��
uniform vec3 ViewPos;  //��������ϵ�����λ��

struct Material
{
    float diffuse;
    float specular;
};

uniform Material material;

void main()
{
//color = vec4(vertexColor,1.0f);//������ϲ��Ե���͸���Ȳ���Ч��
    vec3 lightDirection = normalize(LightPos-FragPos); //���շ���
    vec3 viewDirection = normalize(ViewPos - FragPos); //��Ұ����
    vec3 norm = normalize(Normal);

    //��������
    vec3 ambient = 0.5f * vertexColor;

    //������
    float diff = material.diffuse * max(dot(norm,lightDirection),0.0f);
    vec3 diffuse = diff * vertexColor;
    //���淴��
    vec3 halfAngle = normalize(viewDirection + lightDirection);
    float spec = material.specular * pow(max(dot(norm,halfAngle),0.0f),64.0f);
    vec3 specular = spec * vertexColor;

    color = vec4(ambient + diffuse + specular,1.0f);
}