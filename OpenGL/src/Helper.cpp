#include "Helper.h"

Helper::Helper()
{
}

Helper::~Helper()
{
}

void Helper::setup(GLFWwindow* window, int displayWidth, int displayHeight) {

	/*
	* Specifies the part of the window to which OpenGL will
	* draw (in pixels), convert from normalised to pixels.
	*/
	glViewport(0, 0, displayWidth, displayHeight);
	/*
	* Defines the property of the camera that views the objects
	* in the world coordinate frame. Here you typically set the
	* zoom factor, aspec ratio and the near and far clipping planes.
	*/
	glMatrixMode(GL_PROJECTION);
	/*
	* Replace the current matrix with the identity matrix and
	* start us a fresh because matrix transforms such as
	* glOrtho and glRotated cumulate, basically put us at (0, 0, 0).
	*/
	glLoadIdentity();
	// Set Coordinates System.
	glOrtho(0, displayWidth, 0, displayHeight, 0, 1);
	/*
	* Modelview matrix defines how your objects are transformed
	* in your world.
	*/
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Helper::drawPoint(GLint pointVertex[], GLfloat size) {
	glEnableClientState(GL_VERTEX_ARRAY);
	glPointSize(size);
	glVertexPointer(2, GL_INT, 0, pointVertex);
	glDrawArrays(GL_POINTS, 0, 1);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Helper::drawPixel(GLfloat x, GLfloat y) {
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void Helper::drawQuad(GLfloat vertices[]) {
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Helper::drawLine(GLfloat vertices[]) {
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_LINES, 0, 2);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Helper::drawLine(GLfloat vertices[], GLint width) {
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(width);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_LINES, 0, 2);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_LINE_SMOOTH);
}

void Helper::drawLine(GLfloat vertices[], GLint width, GLint stipple) {
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_LINE_STIPPLE);
	glPushAttrib(GL_LINE_BIT);
	glLineWidth(10);
	glLineStipple(1, stipple);
	glLineWidth(width);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_LINES, 0, 2);
	glDisableClientState(GL_VERTEX_ARRAY);
	glPopAttrib();
	glDisable(GL_LINE_STIPPLE);
	glDisable(GL_LINE_SMOOTH);
}

void Helper::drawLineStripLoop(GLfloat vertices[], int size) {
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_LINE_LOOP, 0, size);
	glDisableClientState(GL_VERTEX_ARRAY);

}

void Helper::drawLineStripLoop(GLfloat vertices[], int size, GLfloat color[]) {
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColorPointer(3, GL_FLOAT, 0, color);
	glDrawArrays(GL_LINE_LOOP, 0, size);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

}

void Helper::drawPolygon(GLfloat vertices[], int size) {

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_POLYGON, 0, size);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Helper::drawPolygon(GLfloat vertices[], int size, GLfloat color[]) {

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColorPointer(3, GL_FLOAT, 0, color);
	glDrawArrays(GL_POLYGON, 0, size);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

/* Bresenham line-drawing procedure for |m| < 1.0. */
void Helper::drawBresenhamsLine(int x0, int y0, int xEnd, int yEnd) {
	int dx = fabs(xEnd - x0);
	int dy = fabs(yEnd - y0);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
	int x, y;
	/* Determine which endpoint to use as start position. */
	if (x0 > xEnd) {
		x = xEnd;
		y = yEnd;
		xEnd = x0;
	}
	else {
		x = x0;
		y = y0;
	}

	drawPixel(x, y);

	while (x < xEnd) {
		x++;
		if (p < 0)
			p += twoDy;
		else {
			y++;
			p += twoDyMinusDx;
		}

		drawPixel(x, y);
	}
	glFlush();
}

void Helper::moveQuadToRight(float vertices[]) {
	vertices[0] += 1;
	vertices[3] += 1;
	vertices[6] += 1;
	vertices[9] += 1;
}

void Helper::moveQuadToLeft(float vertices[]) {
	vertices[0] -= 1;
	vertices[3] -= 1;
	vertices[6] -= 1;
	vertices[9] -= 1;
}

void Helper::scaleQuadUpper(float vertices[]) {
	vertices[0] -= 1;
	vertices[1] += 1;
	vertices[3] += 1;
	vertices[4] += 1;
	vertices[6] += 1;
	vertices[7] -= 1;
	vertices[9] -= 1;
	vertices[10] -= 1;
}

void Helper::scaleQuadDown(float vertices[]) {
	vertices[0] += 1;
	vertices[1] -= 1;
	vertices[3] -= 1;
	vertices[4] -= 1;
	vertices[6] -= 1;
	vertices[7] += 1;
	vertices[9] += 1;
	vertices[10] += 1;
}
