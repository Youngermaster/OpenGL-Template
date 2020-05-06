#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include<iostream>
#include <stdlib.h>
#include <cmath>

class Helper
{
public:
	Helper();
	~Helper();
	void setup(GLFWwindow* window, int width, int height);

	void drawPixel(GLfloat x, GLfloat y);

	void drawPoint(GLint pointVertex[], GLfloat size);

	void drawQuad(GLfloat vertices[]);

	void drawLine(GLfloat vertices[]);
	void drawLine(GLfloat vertices[], GLint width);
	void drawLine(GLfloat vertices[], GLint width, GLint stipple);

	void drawLineStripLoop(GLfloat vertices[], int size);
	void drawLineStripLoop(GLfloat vertices[], int size, GLfloat color[]);

	void drawPolygon(GLfloat vertices[], int size);
	void drawPolygon(GLfloat vertices[], int size, GLfloat color[]);

	void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius);
	void drawHollowCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius);

	void drawBresenhamsLine(int x0, int y0, int xEnd, int yEnd);

	void moveQuadToRight(float vertices[]);
	void moveQuadToLeft(float vertices[]);
	void scaleQuadUpper(float vertices[]);
	void scaleQuadDown(float vertices[]);
private:
};
