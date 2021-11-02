//#include <iostream>
////GLEW
//#define GLEW_STATIC
//#include <GL/glew.h>
////GLFW
//#include <GLFW/glfw3.h>
//#include "Shader.h"
//#include "SOIL2/SOIL2.h"
//#include "SOIL2/stb_image.h"
//const GLint WIDTH = 800, HEIGHT = 600;//���ڳ���
//
//
//int main()
//{
//	glfwInit();//��ʼ��
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//���汾��
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//���汾��
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // must for Mac
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "B19030311", nullptr,
//		nullptr);//��������
//	// next two lines are for mac retina display
//	int screenWidth, screenHeight;
//	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);//��ȡ���������Դ�
//	if (nullptr == window)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glewExperimental = GL_TRUE;
//	if (GLEW_OK != glewInit())
//	{
//		std::cout << "Failed to initialise GLEW" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//
//
//	Shader ourShader = Shader("res/shaders/core.vs", "res/shaders/core.fs");
//
//	GLfloat vertices[] =
//	{
//		 0.5f,0.5f,0.0f,           1.0f,0.0f,0.0f,         1.0f,1.0f,                 //top right
//		 0.5f,-0.5f,0.0f,          1.0f,0.0f,0.0f,         1.0f,0.0f,                 // bottom right
//		 -0.5f,-0.5f,0.0f,         1.0f,0.0f,0.0f,         0.0f,0.0f,                   //bottom left
//		 -0.5f,0.5f,0.0f,          1.0f,0.0f,0.0f,         0.0f,1.0f                     //top left
//	};
//	unsigned int indices[] =
//	{
//		0,1,3,
//		1,2,3
//	};
//
//
//	//������
//	GLuint VAO, VBO;//�ɶԳ���
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	//����VAO��VBO(˳������)
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//
//	//��������
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,
//		GL_STATIC_DRAW);
//
//	//��������
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);//(��������ÿ��������λ�û�ø��������������ʲôλ��ȡ)
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(2);
//	GLuint EBO;
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//
//	GLuint texture0;
//	int width, height;
//	glGenTextures(1, &texture0);
//	glBindTexture(GL_TEXTURE_2D, texture0);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	unsigned char* image = SOIL_load_image("res/images/1.jpg", &width, &height, 0, SOIL_LOAD_RGBA);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
//	glGenerateMipmap(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, 0);
//
//	while (!glfwWindowShouldClose(window)) {
//		float time = glfwGetTime();
//		glViewport(0, 0, screenWidth, screenHeight);
//		glfwPollEvents();
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//		ourShader.Use();
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture0);
//		glUniform1i(glGetUniformLocation(ourShader.Program, "texture0"), 0);
//		//glUseProgram(shaderProgram);
//		glUniform1f(glGetUniformLocation(ourShader.Program, "time"), time);
//
//
//		glBindVertexArray(VAO);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//		glBindVertexArray(0);
//		glBindTexture(GL_TEXTURE_2D, 0);
//		glfwSwapBuffers(window);//�������棨˫���棩
//	}
//	glfwTerminate();
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//	glDeleteTextures(1, &texture0);
//	//glDeleteProgram(shaderProgram);
//	return 0;
//}