#include "stdafx.h"
#include <Windows.h>
#include "include\GL\GL.H"
#include "include\GL\GLU.H"
#include "include\GL\glut.h"
#include <math.h>

double rotate_y = 0;
double rotate_x = 0;

float x_mercury = 0;
float x_venus = 0;
float x_earth = 0;
float x_moon = 0;
float x_mars = 0;
float x_jupiter = 0;
float x_saturn = 0;
float x_uranus = 0;
float x_neptune = 0;

float rot_sun = 0;
float rot_mercury = 0;
float rot_venus = 0;
float rot_earth = 0;
float rot_moon = 0;
float rot_mars = 0;
float rot_jupiter = 0;
float rot_saturn = 0;
float rot_uranus = 0;
float rot_neptune = 0;


// Function to rotate project with keys
void specialKeys(int key, int x, int y) {

	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;

	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;

	else if (key == GLUT_KEY_UP)
		rotate_x += 5;

	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;

}


// Timer to rotate
void timer(int a) {

	x_mercury += 47.87 / 2;
	x_venus += 53.02 / 2;
	x_earth += 29.78 / 2;
	x_moon += 4.0 / 2;
	x_mars += 24.07 / 2;
	x_jupiter += 13.07 / 2;
	x_saturn += 9.69 / 2;
	x_uranus += 6.81 / 2;
	x_neptune += 5.43 / 2;

	rot_sun += 80;
	rot_mercury += 40;
	rot_venus += 10;
	rot_earth += 180 - 24;
	rot_moon += 100;
	rot_mars += 180 - 25;
	rot_jupiter += 180 - 10;
	rot_saturn += 180 - 11;
	rot_uranus += 180 - 17;
	rot_neptune += 180 - 16;

	glutPostRedisplay();

}


// Function to load texture images
GLuint LoadTexture(const char * filename, int width, int height) {

	GLuint texture;
	unsigned char * data;

	FILE * file;
	errno_t err = fopen_s(&file, filename, "rb");

	if (file == NULL) return 0;
	data = (unsigned char *)malloc(width * height * 3);
	fread(data, width * height * 3, 1, file);
	fclose(file);

	for (int i = 0; i < width * height; ++i)
	{
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];

		data[index] = R;
		data[index + 2] = B;

	}

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
	free(data);

	return texture;
}



void MyDisplay(void) {

	//  Borrar pantalla y Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// The new scene
	glLoadIdentity();

	glTranslatef(0, 20.0, -50.0f);

	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

	glTranslatef(0.0, -50.0, 0.0);

	glPushMatrix();

	// -------------------------------------- SUN --------------------------------------

	glRotatef(rot_sun, 0.0, 1.0, 0.0); // Rotation center of mass

	// Texture for the sphere
	GLuint texture_sun;
	texture_sun = LoadTexture("textures/sun.bmp", 640, 425);
	glBindTexture(GL_TEXTURE_2D, texture_sun);

	// Sphere
	glBegin(GL_POLYGON);

	GLUquadric* sun;
	sun = gluNewQuadric();
	gluQuadricDrawStyle(sun, GLU_FILL);
	gluQuadricTexture(sun, GL_TRUE);
	gluQuadricNormals(sun, GLU_SMOOTH);
	gluSphere(sun, (1392000 / 200000), 10, 10);

	glPopMatrix();
	glPushMatrix();


	// -------------------------------------- MERCURY --------------------------------------
	glRotatef(x_mercury, 0.0, 1.0, 0.0);
	glTranslatef(57910 / 2000, 0.0, 0.0);

	glRotatef(rot_mercury, 0.0, 1.0, 0.0); // Rotation center of mass

	// Texture for the sphere
	GLuint texture_mercury;
	texture_mercury = LoadTexture("textures/mercury.bmp", 871, 629);
	glBindTexture(GL_TEXTURE_2D, texture_mercury);

	// Sphere
	GLUquadric* mercury;
	mercury = gluNewQuadric();
	gluQuadricDrawStyle(mercury, GLU_FILL);
	gluQuadricTexture(mercury, GL_TRUE);
	gluQuadricNormals(mercury, GLU_SMOOTH);

	gluSphere(mercury, (2440 / 2000), 10, 10);

	glPopMatrix();
	glPushMatrix();

	// -------------------------------------- VENUS --------------------------------------
	glRotatef(x_venus, 0.0, 1.0, 0.0);
	glTranslatef(108200 / 2000, 0.0, 0.0);

	glRotatef(rot_venus, 0.0, 1.0, 0.0); // Rotation center of mass

	// Texture for the sphere
	GLuint texture_venus;
	texture_venus = LoadTexture("textures/venus.bmp", 1019, 673);
	glBindTexture(GL_TEXTURE_2D, texture_venus);

	// Sphere
	GLUquadric* venus;
	venus = gluNewQuadric();
	gluQuadricDrawStyle(venus, GLU_FILL);
	gluQuadricTexture(venus, GL_TRUE);
	gluQuadricNormals(venus, GLU_SMOOTH);

	gluSphere(venus, (6052 / 2000), 10, 10);

	glPopMatrix();
	glPushMatrix();

	// -------------------------------------- EARTH --------------------------------------
	glRotatef(x_earth, 0.0, 1.0, 0.0);
	glTranslatef(149600 / 2000, 0.0, 0.0);

	glPushMatrix();

	glRotatef(rot_earth, 0.0, 1.0, 0.0); // Rotation center of mass

	// Texture for the sphere
	GLuint texture_earth;
	texture_earth = LoadTexture("textures/earth.bmp", 1024, 512);
	glBindTexture(GL_TEXTURE_2D, texture_earth);

	// Sphere
	GLUquadric* earth;
	earth = gluNewQuadric();
	gluQuadricDrawStyle(earth, GLU_FILL);
	gluQuadricTexture(earth, GL_TRUE);
	gluQuadricNormals(earth, GLU_SMOOTH);

	gluSphere(earth, (6371 / 2000), 10, 10);

	// -------------------------------------- MOON --------------------------------------
	glPopMatrix();
	glRotatef(x_moon, 0.0, 1.0, 0.0);
	glTranslatef((3844 / 200 + 5000 / 2000) / 2, 0.0, 0.0);

	glRotatef(rot_moon, 0.0, 1.0, 0.0); // Rotation center of mass

	// Texture for the sphere
	GLuint texture_moon;
	texture_moon = LoadTexture("textures/moon.bmp", 323, 242);
	glBindTexture(GL_TEXTURE_2D, texture_moon);

	// Sphere
	GLUquadric* moon;
	moon = gluNewQuadric();
	gluQuadricDrawStyle(moon, GLU_FILL);
	gluQuadricTexture(moon, GL_TRUE);
	gluQuadricNormals(moon, GLU_SMOOTH);

	gluSphere(moon, (1737 / 1000), 10, 10);

	glPopMatrix();
	glPushMatrix();

	// -------------------------------------- MARS --------------------------------------
	glRotatef(x_mars, 0.0, 1.0, 0.0);
	glTranslatef(227940 / 2000, 0.0, 0.0);

	glRotatef(rot_mars, 0.0, 1.0, 0.0); // Rotation center of mass

	// Texture for the sphere
	GLuint texture_mars;
	texture_mars = LoadTexture("textures/mars.bmp", 624, 351);
	glBindTexture(GL_TEXTURE_2D, texture_mars);

	// Sphere
	GLUquadric* mars;
	mars = gluNewQuadric();
	gluQuadricDrawStyle(mars, GLU_FILL);
	gluQuadricTexture(mars, GL_TRUE);
	gluQuadricNormals(mars, GLU_SMOOTH);

	gluSphere(mars, (3390 / 2000), 10, 10);

	glPopMatrix();
	glPushMatrix();

	// -------------------------------------- JUPITER --------------------------------------
	glRotatef(x_jupiter, 0.0, 1.0, 0.0);
	glTranslatef(778330 / 3000, 0.0, 0.0);

	glRotatef(rot_jupiter, 0.0, 1.0, 0.0); // Rotation center of mass

	// Texture for the sphere
	GLuint texture_jupiter;
	texture_jupiter = LoadTexture("textures/jupiter.bmp", 960, 480);
	glBindTexture(GL_TEXTURE_2D, texture_jupiter);

	// Sphere
	GLUquadric* jupiter;
	jupiter = gluNewQuadric();
	gluQuadricDrawStyle(jupiter, GLU_FILL);
	gluQuadricTexture(jupiter, GL_TRUE);
	gluQuadricNormals(jupiter, GLU_SMOOTH);

	gluSphere(jupiter, (69911 / 3000), 10, 10);

	glPopMatrix();
	glPushMatrix();

	// -------------------------------------- SATURN --------------------------------------
	glRotatef(x_saturn, 0.0, 1.0, 0.0);
	glTranslatef(1429000 / 2000, 0.0, 0.0);

	glRotatef(rot_saturn, 0.0, 1.0, 0.0); // Rotation center of mass

	// Texture for the sphere
	GLuint texture_saturn;
	texture_saturn = LoadTexture("textures/saturn.bmp", 477, 321);
	glBindTexture(GL_TEXTURE_2D, texture_saturn);

	// Sphere
	GLUquadric* saturn;
	saturn = gluNewQuadric();
	gluQuadricDrawStyle(saturn, GLU_FILL);
	gluQuadricTexture(saturn, GL_TRUE);
	gluQuadricNormals(saturn, GLU_SMOOTH);

	gluSphere(saturn, (58232 / 2000), 10, 10);

	glPopMatrix();
	glPushMatrix();

	// -------------------------------------- URANUS --------------------------------------
	glRotatef(x_uranus, 0.0, 1.0, 0.0);
	glTranslatef(2870900 / 2000, 0.0, 0.0);

	glRotatef(rot_uranus, 0.0, 1.0, 0.0); // Rotation center of mass

	// Texture for the sphere
	GLuint texture_uranus;
	texture_uranus = LoadTexture("textures/uranus.bmp", 280, 280);
	glBindTexture(GL_TEXTURE_2D, texture_uranus);

	// Sphere
	GLUquadric* uranus;
	uranus = gluNewQuadric();
	gluQuadricDrawStyle(uranus, GLU_FILL);
	gluQuadricTexture(uranus, GL_TRUE);
	gluQuadricNormals(uranus, GLU_SMOOTH);

	gluSphere(uranus, (25326 / 2000), 10, 10);

	glPopMatrix();
	glPushMatrix();

	// -------------------------------------- NEPTUNE --------------------------------------
	glRotatef(x_neptune, 0.0, 1.0, 0.0);
	glTranslatef(4504300 / 2000, 0.0, 0.0);

	glRotatef(rot_neptune, 0.0, 1.0, 0.0); // Rotation center of mass

	// Texture for the sphere
	GLuint texture_neptune;
	texture_neptune = LoadTexture("textures/neptune.bmp", 596, 600);
	glBindTexture(GL_TEXTURE_2D, texture_neptune);

	// Sphere
	GLUquadric* neptune;
	neptune = gluNewQuadric();
	gluQuadricDrawStyle(neptune, GLU_FILL);
	gluQuadricTexture(neptune, GL_TRUE);
	gluQuadricNormals(neptune, GLU_SMOOTH);

	gluSphere(neptune, (25326 / 2000), 10, 10);

	glPopMatrix();

	glEnd();

	glPopMatrix();

	glutTimerFunc(100, timer, 0); // Timer in milliseconds
	// The end of scene
	glFlush();//start processing buffered OpenGL routines
}



void MyInit(void) {
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST); // It test each pixel and decide if it must be shown or not
	glClearColor(0.0, 0.0, 0.0, 0.0);//select clearing (background) color
									 /* initialize viewing values */
	glViewport(0, 0, 300, 300);//window origin and size
	glMatrixMode(GL_PROJECTION);//
	glLoadIdentity();//=1
	gluPerspective(140.0f, (float)(16 / 9), 0.1f, 10000.0f);
	/*
	void gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar);
		fovy: Specifies the field of view angle, in degrees, in the y direction.
		aspect: Specifies the aspect ratio that determines the field of view in the x direction.The aspect ratio is the ratio of x(width) to y(height).
		zNear: Specifies the distance from the viewer to the near clipping plane(always positive).
		zFar: Specifies the distance from the viewer to the far clipping plane(always positive).
	*/
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//=1
}

int main(int argc, char** argv) { //<- for normal API
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);//single buffer and RGBA
	glutInitWindowSize(500, 500);//initial window size
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Sprint");//create widnow, hello title bar
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutSpecialFunc(specialKeys);
	glutMainLoop();//enter main loop and process events
	return 0;
}