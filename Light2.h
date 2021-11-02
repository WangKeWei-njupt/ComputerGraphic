#ifndef Light2_h
#define Light2_h

#include <GL/glew.h>
#include "Shader2.h"

GLfloat vertices_light[] =  //������Դ��С������
{
	//position         
	-0.5f,-0.5f,-0.5f,
	0.5f,-0.5f,-0.5f,
	0.5f,0.5f,-0.5f,
	0.5f,0.5f,-0.5f,
	-0.5f,0.5f,-0.5f,
	-0.5f,-0.5f,-0.5f,

	-0.5f,-0.5f,0.5f,
	0.5f,-0.5f,0.5f,
	0.5f,0.5f,0.5f,
	0.5f,0.5f,0.5f,
	-0.5f,0.5f,0.5f,
	-0.5f,-0.5f,0.5f,

	-0.5f,0.5f,0.5f,
	-0.5f,0.5f,-0.5f,
	-0.5f,-0.5f,-0.5f,
	-0.5f,-0.5f,-0.5f,
	-0.5f,-0.5f,0.5f,
	-0.5f,0.5f,0.5f,

	0.5f,0.5f,0.5f,
	0.5f,0.5f,-0.5f,
	0.5f,-0.5f,-0.5f,
	0.5f,-0.5f,-0.5f,
	0.5f,-0.5f,0.5f,
	0.5f,0.5f,0.5f,

	-0.5f,-0.5f,-0.5f,
	0.5f,-0.5f,-0.5f,
	0.5f,-0.5f,0.5f,
	0.5f,-0.5f,0.5f,
	-0.5f,-0.5f,0.5f,
	-0.5f,-0.5f,-0.5f,

	-0.5f,0.5f,-0.5f,
	0.5f,0.5f,-0.5f,
	0.5f,0.5f,0.5f,
	0.5f,0.5f,0.5f,
	-0.5f,0.5f,0.5f,
	-0.5f,0.5f,-0.5f,
};

class Light2
{
public:
	Light2() {
		this->update();
	}
	void Draw(Shader& shader) {
		glBindVertexArray(this->VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);
	}
private:
	GLuint VAO, VBO;
	void update() {
		//��������
		glGenVertexArrays(1, &this->VAO);
		glGenBuffers(1, &this->VBO);
		//��VAO��VBO
		glBindVertexArray(this->VAO);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
		//��������
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_light), vertices_light, GL_STATIC_DRAW);
		//����VAO
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0); //λ��
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);//���
		glBindVertexArray(0);//���
	}
};

#endif
