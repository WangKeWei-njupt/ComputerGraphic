//#include <iostream>
//#include<Windows.h>
//#define GLEW_STATIC
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include "Shader2.h"
//#include "Camera2.h"
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "glm/gtc/type_ptr.hpp"
//#include "glm/gtx/rotate_vector.hpp"
//#include "Shader2.h"
//#include "Moon.h"
//const GLint WIDTH = 800, HEIGHT = 600;
//void KeyCallback(GLFWwindow *window,int key,int scancode,int action, int mode);//���̲���
//void ScrollCallback(GLFWwindow* window, double xOffset, double yOffset);//����
//void MouseCallback(GLFWwindow* window, double xPos, double yPos);//�����
//void DoMovement();//���̿��ƾ�ͷ
//bool keys[1024];//���м��̲���
//Camera2 camera(glm::vec3(0.0f, 0.0f, 2.0f));
//GLfloat deltaTime = 0.0f;
//GLfloat lastTime = 0.0f;
//GLfloat lastX = WIDTH / 2.0f; //��һ�����xλ��
//GLfloat lastY = HEIGHT / 2.0f; //��һ�����yλ��
//bool firstMouse = true; //�Ƿ�����״��ƶ�
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//���汾��
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//���汾��
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//�����ǻ�opengl���汾��CORE_PROFILE
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);//��ǰ���ݣ�ƻ������
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);//��ֹ���ڵ�����С
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "B19030311", nullptr, nullptr);
//	if (nullptr == window) {
//		std::cout << "Failed to create window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	//���ڸ�����,��ȡʵ��ռ�����Դ�
//	int screenWidth, screenHeight;
//	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);//��ô��ڶ�Ӧ�Դ��С
//	glfwMakeContextCurrent(window);//�Ѵ�����Ϊ��ǰ����
//	glfwSetKeyCallback(window, KeyCallback);//�ڵ�ǰ����ע����̲���
//	glfwSetCursorPosCallback(window, MouseCallback);//ע�����
//	glfwSetScrollCallback(window, ScrollCallback);//ע�����
//	glewExperimental = GL_TRUE;
//	if (GLEW_OK != glewInit()) {
//		std::cout << "Failed to initilize GLEW" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glEnable(GL_DEPTH_TEST);//������Ȳ���
//	glDepthFunc(GL_LESS);
//	glEnable(GL_BLEND);//������ϲ���
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	Shader ourShader = Shader("res/shaders/core3.vs", "res/shaders/core3.fs");
//	Shader moonShader = Shader("res/shaders/moon.vs", "res/shaders/moon.fs");
//	Moon moonModel = Moon(); //��������
//	//������Ϣ
//	//����������
//	GLfloat vertices[] =
//	{
//		//position                      //color
//		-0.5f,-0.5f,-0.5f,              1.0f,0.0f,0.0f,
//		0.5f,-0.5f,-0.5f,               1.0f,0.0f,0.0f,
//		0.5f,0.5f,-0.5f,                1.0f,0.0f,0.0f,
//		0.5f,0.5f,-0.5f,                1.0f,0.0f,0.0f,
//		-0.5f,0.5f,-0.5f,               1.0f,0.0f,0.0f,
//		-0.5f,-0.5f,-0.5f,              1.0f,0.0f,0.0f,
//		-0.5f,-0.5f,0.5f,               0.0f,1.0f,0.0f,
//		0.5f,-0.5f,0.5f,                0.0f,1.0f,0.0f,
//		0.5f,0.5f,0.5f,                 0.0f,1.0f,0.0f,
//		0.5f,0.5f,0.5f,                 0.0f,1.0f,0.0f,
//		-0.5f,0.5f,0.5f,                0.0f,1.0f,0.0f,
//		-0.5f,-0.5f,0.5f,               0.0f,1.0f,0.0f,
//		-0.5f,0.5f,0.5f,                0.0f,0.0f,1.0f,
//		-0.5f,0.5f,-0.5f,               0.0f,0.0f,1.0f,
//		-0.5f,-0.5f,-0.5f,              0.0f,0.0f,1.0f,
//		-0.5f,-0.5f,-0.5f,              0.0f,0.0f,1.0f,
//		-0.5f,-0.5f,0.5f,               0.0f,0.0f,1.0f,
//		-0.5f,0.5f,0.5f,                0.0f,0.0f,1.0f,
//		0.5f,0.5f,0.5f,                1.0f,1.0f,0.0f,
//		0.5f,0.5f,-0.5f,               1.0f,1.0f,0.0f,
//		0.5f,-0.5f,-0.5f,              1.0f,1.0f,0.0f,
//		0.5f,-0.5f,-0.5f,              1.0f,1.0f,0.0f,
//		0.5f,-0.5f,0.5f,               1.0f,1.0f,0.0f,
//		0.5f,0.5f,0.5f,                1.0f,1.0f,0.0f,
//		-0.5f,-0.5f,-0.5f,             1.0f,0.0f,1.0f,
//		0.5f,-0.5f,-0.5f,              1.0f,0.0f,1.0f,
//		0.5f,-0.5f,0.5f,               1.0f,0.0f,1.0f,
//		0.5f,-0.5f,0.5f,               1.0f,0.0f,1.0f,
//		-0.5f,-0.5f,0.5f,              1.0f,0.0f,1.0f,
//		-0.5f,-0.5f,-0.5f,             1.0f,0.0f,1.0f,
//		-0.5f,0.5f,-0.5f,             0.0f,1.0f,1.0f,
//		0.5f,0.5f,-0.5f,              0.0f,1.0f,1.0f,
//		0.5f,0.5f,0.5f,               0.0f,1.0f,1.0f,
//		0.5f,0.5f,0.5f,               0.0f,1.0f,1.0f,
//		-0.5f,0.5f,0.5f,              0.0f,1.0f,1.0f,
//		-0.5f,0.5f,-0.5f,             0.0f,1.0f,1.0f,
//	};
//	//��������
//	GLuint VAO, VBO; //�������ж��󣨸���������ݣ������㻺�����(������)���ɶԳ���
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	//��VAO��VBO
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	//��������
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	//����VAO
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0); //λ��
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat))); //��ɫ
//	glEnableVertexAttribArray(1);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);//���
//	glBindVertexArray(0);//���
//	glm::vec3 moonPos = glm::vec3(1.0f, 0.0f, 0.0f);//��ʼ����λ��
//	//����ѭ��
//	while (!glfwWindowShouldClose(window)) { //���ڲ��ر�ÿһ֡��ˢ�»�ͼ
//		GLfloat currentTime = glfwGetTime();
//		deltaTime = currentTime - lastTime;
//		lastTime = currentTime;
//		glViewport(0, 0, screenWidth, screenHeight);//�����½�λ�ã�0��0���������ĳ��͸�
//		glfwPollEvents();//��ȡ��Ҫ��λ�ñ����Ϣ,�������̵�
//		DoMovement();
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//RGBA
//		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//����ɫ����Ƚ��г�ʼ����ֵ
//		moonPos = glm::rotate(moonPos,glm::radians(0.5f),glm::vec3(0.0f,1.0f,0.0f));  //����λ�ñ任�ٶ�
//		glm::mat4 view = camera.GetViewMatrix();
//		glm::mat4 projection = glm::perspective(glm::radians(camera.GetZoom()), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);//����͸��ͶӰ(����)
//		glm::mat4 transform = glm::mat4(1.0f); //4*4����,�޸Ķ���λ����Ϣ
//		transform = glm::translate(transform, moonPos);
//		transform = glm::scale(transform, glm::vec3(0.1f, 0.1f, 0.1f));
//		moonShader.Use();
//		glUniformMatrix4fv(glGetUniformLocation(moonShader.Program, "transform"), 1, GL_FALSE, glm::value_ptr(transform));
//		glUniformMatrix4fv(glGetUniformLocation(moonShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
//		glUniformMatrix4fv(glGetUniformLocation(moonShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
//		moonModel.Draw(moonShader);
//		ourShader.Use();
//		transform = glm::mat4(1.0f);
//		transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, -2.0f));//ƽ��
//		transform = glm::rotate(transform, glm::radians(20.0f)*static_cast<GLfloat>(glfwGetTime()), glm::vec3(0.0f, 1.0f, 0.0f));//��ת�任
//		transform = glm::scale(transform, glm::vec3(0.5f, 0.5f, 0.5f));//����
//		GLuint transLoc = glGetUniformLocation(ourShader.Program,"transform");
//		glUniformMatrix4fv(transLoc, 1, GL_FALSE, glm::value_ptr(transform));
//
//
//		glUniformMatrix4fv(glGetUniformLocation(ourShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
//		glUniformMatrix4fv(glGetUniformLocation(ourShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES,0,36);
//		glBindVertexArray(0);
//		glfwSwapBuffers(window);//˫�������
//	}
//	glfwTerminate();
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	return 0;
//}
//void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)//���̲���
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) { //����esc
//		glfwSetWindowShouldClose(window, GL_TRUE);
//	}
//	//��¼����
//	if (key >= 0 && key < 1024) {
//		if (action == GLFW_PRESS) {
//			keys[key] = true;
//		}
//		else if (action == GLFW_RELEASE) {
//			keys[key] = false;
//		}
//	}
//}
//void DoMovement()
//{
//	if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP]) {
//		camera.ProcessKeyboard(FORWARD, deltaTime);
//	}
//	if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN]) {
//		camera.ProcessKeyboard(BACKWARD, deltaTime);
//	}
//	if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT]) {
//		camera.ProcessKeyboard(LEFT, deltaTime);
//	}
//	if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT]) {
//		camera.ProcessKeyboard(RIGHT, deltaTime);
//	}
//}
//void ScrollCallback(GLFWwindow* window, double xOffset, double yOffset)
//{
//}
//void MouseCallback(GLFWwindow* window, double xPos, double yPos)
//{
//	if (firstMouse) {
//		lastX = xPos;
//		lastY = yPos;
//		firstMouse = false;
//	}
//	GLfloat xOffset = xPos - lastX;
//	GLfloat yOffset = lastY - yPos;
//	lastX = xPos;
//	lastY = yPos;
//	camera.ProcessMouseMovement(xOffset, yOffset);
//}