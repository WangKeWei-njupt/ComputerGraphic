#include <iostream>
#include<Windows.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Shader2.h"
#include "Camera2.h"
#include "Light2.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/rotate_vector.hpp"

const GLint WIDTH = 800, HEIGHT = 600;
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);//���̲���
void ScrollCallback(GLFWwindow* window, double xOffset, double yOffset);//����
void MouseCallback(GLFWwindow* window, double xPos, double yPos);//�����

void DoMovement();//���̿��ƾ�ͷ

bool keys[1024];//���м��̲���
Camera2 camera(glm::vec3(0.0f, 0.0f, 2.0f));
GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;
GLfloat lastX = WIDTH / 2.0f; //��һ�����xλ��
GLfloat lastY = HEIGHT / 2.0f; //��һ�����yλ��
bool firstMouse = true; //�Ƿ�����״��ƶ�

GLfloat objectX = 0.0f; //�����ʼλ��
GLfloat objectY = 0.0f;
GLfloat objectZ = -2.0f;
const GLfloat OBJECT_SPEED = 6.0f;

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//���汾��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//���汾��
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//�����ǻ�opengl���汾��CORE_PROFILE
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);//��ǰ���ݣ�ƻ������
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);//��ֹ���ڵ�����С

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "B19030235PCA", nullptr, nullptr);

	if (nullptr == window) {
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return -1;
	}

	//���ڸ�����,��ȡʵ��ռ�����Դ�
	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);//��ô��ڶ�Ӧ�Դ��С

	glfwMakeContextCurrent(window);//�Ѵ�����Ϊ��ǰ����
	glfwSetKeyCallback(window, KeyCallback);//�ڵ�ǰ����ע����̲���
	glfwSetCursorPosCallback(window, MouseCallback);//ע�����
	glfwSetScrollCallback(window, ScrollCallback);//ע�����

	glewExperimental = GL_TRUE;

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initilize GLEW" << std::endl;
		glfwTerminate();
		return -1;
	}

	glEnable(GL_DEPTH_TEST);//������Ȳ���
	glDepthFunc(GL_LESS);
	glEnable(GL_BLEND);//������ϲ���
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	Shader ourShader = Shader("res/shaders/core3.vs", "res/shaders/core3.fs");
	Shader lightShader = Shader("res/shaders/light.vs", "res/shaders/light.fs");

	Light2 lightModel = Light2();

	//������Ϣ
	//����������
	GLfloat vertices[] =
	{
		//position                      //color               //������
		-0.5f,-0.5f,-0.5f,              1.0f,0.0f,0.0f,		  0.0f,0.0f,-1.0f,
		0.5f,-0.5f,-0.5f,               1.0f,0.0f,0.0f,		  0.0f,0.0f,-1.0f,
		0.5f,0.5f,-0.5f,                1.0f,0.0f,0.0f,		  0.0f,0.0f,-1.0f,
		0.5f,0.5f,-0.5f,                1.0f,0.0f,0.0f,		  0.0f,0.0f,-1.0f,
		-0.5f,0.5f,-0.5f,               1.0f,0.0f,0.0f,		  0.0f,0.0f,-1.0f,
		-0.5f,-0.5f,-0.5f,              1.0f,0.0f,0.0f,		  0.0f,0.0f,-1.0f,

		-0.5f,-0.5f,0.5f,               0.0f,1.0f,0.0f,		  0.0f,0.0f,1.0f,
		0.5f,-0.5f,0.5f,                0.0f,1.0f,0.0f,		  0.0f,0.0f,1.0f,
		0.5f,0.5f,0.5f,                 0.0f,1.0f,0.0f,		  0.0f,0.0f,1.0f,
		0.5f,0.5f,0.5f,                 0.0f,1.0f,0.0f,		  0.0f,0.0f,1.0f,
		-0.5f,0.5f,0.5f,                0.0f,1.0f,0.0f,		  0.0f,0.0f,1.0f,
		-0.5f,-0.5f,0.5f,               0.0f,1.0f,0.0f,		  0.0f,0.0f,1.0f,

		-0.5f,0.5f,0.5f,                0.0f,0.0f,1.0f,		  -1.0f,0.0f,0.0f,
		-0.5f,0.5f,-0.5f,               0.0f,0.0f,1.0f,		  -1.0f,0.0f,0.0f,
		-0.5f,-0.5f,-0.5f,              0.0f,0.0f,1.0f,		  -1.0f,0.0f,0.0f,
		-0.5f,-0.5f,-0.5f,              0.0f,0.0f,1.0f,		  -1.0f,0.0f,0.0f,
		-0.5f,-0.5f,0.5f,               0.0f,0.0f,1.0f,		  -1.0f,0.0f,0.0f,
		-0.5f,0.5f,0.5f,                0.0f,0.0f,1.0f,		  -1.0f,0.0f,0.0f,

		0.5f,0.5f,0.5f,                1.0f,1.0f,0.0f,		   1.0f,0.0f,0.0f,
		0.5f,0.5f,-0.5f,               1.0f,1.0f,0.0f,		   1.0f,0.0f,0.0f,
		0.5f,-0.5f,-0.5f,              1.0f,1.0f,0.0f,		   1.0f,0.0f,0.0f,
		0.5f,-0.5f,-0.5f,              1.0f,1.0f,0.0f,		   1.0f,0.0f,0.0f,
		0.5f,-0.5f,0.5f,               1.0f,1.0f,0.0f,		   1.0f,0.0f,0.0f,
		0.5f,0.5f,0.5f,                1.0f,1.0f,0.0f,		   1.0f,0.0f,0.0f,

		-0.5f,-0.5f,-0.5f,             1.0f,0.0f,1.0f,		   0.0f,-1.0f,0.0f,
		0.5f,-0.5f,-0.5f,              1.0f,0.0f,1.0f,		   0.0f,-1.0f,0.0f,
		0.5f,-0.5f,0.5f,               1.0f,0.0f,1.0f,		   0.0f,-1.0f,0.0f,
		0.5f,-0.5f,0.5f,               1.0f,0.0f,1.0f,		   0.0f,-1.0f,0.0f,
		-0.5f,-0.5f,0.5f,              1.0f,0.0f,1.0f,		   0.0f,-1.0f,0.0f,
		-0.5f,-0.5f,-0.5f,             1.0f,0.0f,1.0f,		   0.0f,-1.0f,0.0f,

		-0.5f,0.5f,-0.5f,             0.0f,1.0f,1.0f,		   0.0f,1.0f,0.0f,
		0.5f,0.5f,-0.5f,              0.0f,1.0f,1.0f,		   0.0f,1.0f,0.0f,
		0.5f,0.5f,0.5f,               0.0f,1.0f,1.0f,		   0.0f,1.0f,0.0f,
		0.5f,0.5f,0.5f,               0.0f,1.0f,1.0f,		   0.0f,1.0f,0.0f,
		-0.5f,0.5f,0.5f,              0.0f,1.0f,1.0f,		   0.0f,1.0f,0.0f,
		-0.5f,0.5f,-0.5f,             0.0f,1.0f,1.0f,		   0.0f,1.0f,0.0f,

	};

	//��������
	GLuint VAO, VBO; //�������ж��󣨸���������ݣ������㻺�����(������)���ɶԳ���
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//��VAO��VBO
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//��������
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//����VAO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)0); //λ��
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat))); //��ɫ
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat))); //������
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);//���
	glBindVertexArray(0);//���


	glm::vec3 lightPos = glm::vec3(0.0f, 1.5f, 0.0f);//��ʼ��Դλ��

	//����ѭ��
	while (!glfwWindowShouldClose(window)) { //���ڲ��ر�ÿһ֡��ˢ�»�ͼ
		GLfloat currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		glViewport(0, 0, screenWidth, screenHeight);//�����½�λ�ã�0��0���������ĳ��͸�
		glfwPollEvents();//��ȡ��Ҫ��λ�ñ����Ϣ,�������̵�
		DoMovement();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//����ɫ����Ƚ��г�ʼ����ֵ
		lightPos = glm::rotate(lightPos, glm::radians(0.5f), glm::vec3(1.0f, 1.0f, 1.0f));
		glm::mat4 view = camera.GetViewMatrix();
		glm::mat4 projection = glm::perspective(glm::radians(camera.GetZoom()), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);//����͸��ͶӰ(����)
		glm::mat4 transform = glm::mat4(1.0f); 
		transform = glm::translate(transform, lightPos);
		transform = glm::scale(transform, glm::vec3(0.1f, 0.1f, 0.1f));

		lightShader.Use();
		glUniformMatrix4fv(glGetUniformLocation(lightShader.Program, "transform"), 1, GL_FALSE, glm::value_ptr(transform));
		glUniformMatrix4fv(glGetUniformLocation(lightShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(lightShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		lightModel.Draw(lightShader);

		ourShader.Use();
		transform = glm::mat4(1.0f);
		transform = glm::translate(transform, glm::vec3(objectX, objectY, objectZ));//ƽ��
		transform = glm::scale(transform, glm::vec3(0.8f, 0.8f, 0.8f));//����

		GLuint transLoc = glGetUniformLocation(ourShader.Program, "transform");
		glUniformMatrix4fv(transLoc, 1, GL_FALSE, glm::value_ptr(transform));


		glUniformMatrix4fv(glGetUniformLocation(ourShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(ourShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		glUniform3f(glGetUniformLocation(ourShader.Program, "ViewPos"), camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
		glUniform3f(glGetUniformLocation(ourShader.Program, "LightPos"), lightPos.x, lightPos.y, lightPos.z);
		glUniform1f(glGetUniformLocation(ourShader.Program, "material.diffuse"), 0.4f);
		glUniform1f(glGetUniformLocation(ourShader.Program, "material.specular"), 0.4f);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);
		glfwSwapBuffers(window);//˫�������

	}
	glfwTerminate();
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	return 0;
}

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)//���̲���
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) { //����esc
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	//��¼����
	if (key >= 0 && key < 1024) {
		if (action == GLFW_PRESS) {
			keys[key] = true;
		}
		else if (action == GLFW_RELEASE) {
			keys[key] = false;
		}
	}
}

void DoMovement()
{
	if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP]) {
		objectY += deltaTime * OBJECT_SPEED; //����
	}
	if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN]) {
		objectY -= deltaTime * OBJECT_SPEED; ////����
	}
	if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT]) {
		objectX -= deltaTime * OBJECT_SPEED; //����
	}
	if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT]) {
		objectX += deltaTime * OBJECT_SPEED; //����
	}
}

void ScrollCallback(GLFWwindow* window, double xOffset, double yOffset)
{

}
void MouseCallback(GLFWwindow* window, double xPos, double yPos)
{

	if (firstMouse) {
		lastX = xPos;
		lastY = yPos;
		firstMouse = false;
	}
	GLfloat xOffset = xPos - lastX;
	GLfloat yOffset = lastY - yPos;
	lastX = xPos;
	lastY = yPos;

	camera.ProcessMouseMovement(xOffset, yOffset);
}