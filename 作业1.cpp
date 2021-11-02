//#include<iostream>
//
////GLEW
//#define GLEW_STATIC
//#include<GL/glew.h>
//
////GLFW
//#include<GLFW/glfw3.h>
//#include "Shader.h"
//
//const GLint WIDTH = 800, HEIGHT = 600;
////const GLchar *vertexShaderCode = "#version 330 core\n"
////"layout(location = 0) in vec3 position;\n"
////"void main()\n"
////"{\n"
////"gl_Position = vec4(position,1.0f);\n"
////"}";
////const GLchar *fragmentShaderCode = "#version 330 core\n"
////"out vec4 color;\n"
////"void main()\n"
////"{\n"
////"color = vec4(1.0f,0.5f,0.2f,1.0f);\n"
////"}";
//
//int main() {
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "B19030311", nullptr, nullptr);
//	// next two lines are for mac retina display
//	int screenWidth, screenHeight;
//	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
//
//	if (nullptr == window) {
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glewExperimental = GL_TRUE;
//
//	if (GLEW_OK != glewInit()) {
//		std::cout << "Failed to initialize GLEW" << std::endl;
//		return -1;
//	}
//
//
//	Shader ourShader = Shader("res/shaders/core1.vs", "res/shaders/core1.fs");
//
//	
//	
//	GLfloat vertices[] = {
//		// position           //color
//		0.5f,0.5f,0.0f,       1.0f,0.0f,0.0f,  //top right
//		0.5f,-0.5f,0.0f,      1.0f,0.0f,0.0f,   //bottom right
//		-0.5f,-0.5f,0.0f,     1.0f,0.0f,0.0f,  //bottom left
//		-0.5f,0.5f,0.0f,      1.0f,0.0f,0.0f,  //top left
//	};
//
//	unsigned int indices[] = {
//		0,1,3,
//		1,2,3
//	};
//
//	// the data should be transfered to the memory on Graphics Card
//	GLuint VAO, VBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	// connect the VAO and VBO
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	// transfer the data
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	// set the attribute
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//
//	GLuint EBO;
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//
//	while (!glfwWindowShouldClose(window))
//	{
//		float time = glfwGetTime();
//		float colorValue = sin(time) / 2.0f + 0.5f;//设置颜色值范围0--1
//		int vertexColorLocation = glGetUniformLocation(ourShader.Program, "ourColor");//获取uniform的位置索引
//		// glUniform4f(vertexColorLocation, colorValue, 0.0f, 0.0f, 1.0f);
//		if((int)time%2==0)// 红-绿交替
//			glUniform4f(vertexColorLocation, 1.0f, 0.0f, 0.0f, 1.0f);
//		else
//			glUniform4f(vertexColorLocation, 0.0f, 1.0f, 0.0f, 1.0f);
//		glViewport(0, 0, screenWidth, screenHeight);
//		glfwPollEvents();
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		/*glUseProgram(shaderProgram);*/
//		ourShader.Use();
//		glUniform1f(glGetUniformLocation(ourShader.Program, "time"), time);
//		glBindVertexArray(VAO);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//		/*glDrawArrays(GL_TRIANGLES, 0, 6);*/
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//		glBindVertexArray(0);
//		glfwSwapBuffers(window);
//	}
//
//	glfwTerminate();
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//	/*glDeleteProgram(shaderProgram);*/
//	return 0;
//}