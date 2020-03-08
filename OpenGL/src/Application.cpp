#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(void) {
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Challenge One", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	/* Make the windows's context current */
	glfwMakeContextCurrent(window);

	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glewInit();

	std::cout << glGetString(GL_VERSION) << std::endl;

	GLfloat pointVertex[] = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };


	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		/* Render here */

		glEnableClientState(GL_VERTEX_ARRAY);
		glPointSize(200);
		glVertexPointer(2, GL_FLOAT, 0, pointVertex);
		glDrawArrays(GL_POINT, 0, 1);
		glDisableClientState(GL_VERTEX_ARRAY);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events*/
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}