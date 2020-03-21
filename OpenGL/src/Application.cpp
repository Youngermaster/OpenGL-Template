#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<iostream>
#include "Helper.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define LOG(x) std::cout << x << std::endl

int main(void) {
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenGL Template", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	/* Make the windows's context current */
	glfwMakeContextCurrent(window);

	glewInit();

	Helper helper = Helper();
	helper.setup(window, SCREEN_WIDTH, SCREEN_HEIGHT);

	GLfloat quadVertices[] =
	{
		300, 300, 0.0, // top right corner
		50, 300, 0.0, // top left corner
		50, 50, 0.0, // bottom left corner
		300, 50, 0.0 // bottom right corner
	};

	GLfloat colorRed[]{
		255, 0, 0,
		255, 0, 0,
		255, 0, 0,
		255, 0, 0,
	};

	GLfloat lineVertices[] =
	{
		200, 100, 0,
		100, 300, 0
	};

	GLfloat lineVertices2[] =
	{
		300, 200, 0,
		200, 400, 0
	};

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		/* Render here */

		helper.drawPolygon(quadVertices, 4, colorRed);
		helper.drawLine(lineVertices, 5);
		helper.drawLine(lineVertices2, 4, 0x00FF);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events*/
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}