/*--------------------------------------------------------------------
Name: Mina Shoaib Rahman Saikat
Roll: 0705096
Sec : B
CSE, BUET
Graphics Engine is copyright protected by Mina Shoaib Rahman Saikat
---------------------------------------------------------------------*/
#include <cmath>
#include "Vector.h"
extern GLuint lowPiller,upPiller,arc,railLine,water;
#define PI	3.14159265

/*--------------------------------------------------------------------
Sets eight cameras with white color
--------------------------------------------------------------------*/
void setLight0(float x, float y, float z, float d, float r, float g, float b) {
	GLfloat light_position[] = { x, y, z, d };
	GLfloat light_color[] = { r, g, b, 1 };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_color);
}

void setLight1(float x, float y, float z, float d, float r, float g, float b) {
	GLfloat light_position[] = { x, y, z, d };
	GLfloat light_color[] = { r, g, b, 1 };

	glLightfv(GL_LIGHT1, GL_POSITION, light_position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_color);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_color);
}

void setLight2(float x, float y, float z, float d, float r, float g, float b) {
	GLfloat light_position[] = { x, y, z, d };
	GLfloat light_color[] = { r, g, b, 1 };

	glLightfv(GL_LIGHT2, GL_POSITION, light_position);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_color);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light_color);
}

void setLight3(float x, float y, float z, float d, float r, float g, float b) {
	GLfloat light_position[] = { x, y, z, d };
	GLfloat light_color[] = { r, g, b, 1 };

	glLightfv(GL_LIGHT3, GL_POSITION, light_position);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, light_color);
	glLightfv(GL_LIGHT3, GL_SPECULAR, light_color);
}

void setLight4(float x, float y, float z, float d, float r, float g, float b) {
	GLfloat light_position[] = { x, y, z, d };
	GLfloat light_color[] = { r, g, b, 1 };

	glLightfv(GL_LIGHT4, GL_POSITION, light_position);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, light_color);
	glLightfv(GL_LIGHT4, GL_SPECULAR, light_color);
}

void setLight5(float x, float y, float z, float d, float r, float g, float b) {
	GLfloat light_position[] = { x, y, z, d };
	GLfloat light_color[] = { r, g, b, 1 };

	glLightfv(GL_LIGHT5, GL_POSITION, light_position);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, light_color);
	glLightfv(GL_LIGHT5, GL_SPECULAR, light_color);
}

void setLight6(float x, float y, float z, float d, float r, float g, float b) {
	GLfloat light_position[] = { x, y, z, d };
	GLfloat light_color[] = { r, g, b, 1 };

	glLightfv(GL_LIGHT6, GL_POSITION, light_position);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, light_color);
	glLightfv(GL_LIGHT6, GL_SPECULAR, light_color);
}

void setLight7(float x, float y, float z, float d, float r, float g, float b) {
	GLfloat light_position[] = { x, y, z, d };
	GLfloat light_color[] = { r, g, b, 1 };

	glLightfv(GL_LIGHT7, GL_POSITION, light_position);
	glLightfv(GL_LIGHT7, GL_DIFFUSE, light_color);
	glLightfv(GL_LIGHT7, GL_SPECULAR, light_color);
}

/*--------------------------------------------------------------------
Next three functions set the material properties
--------------------------------------------------------------------*/

void setMatAmbientColor(float r, float g, float b, float a) {
	GLfloat mat_ambient[] = { r, g, b, a };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
}

void setMatDiffuseColor(float r, float g, float b, float a) {
	GLfloat mat_diffuse[] = { r, g, b, a };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
}

void setMatSpecularColor(float r, float g, float b, float a) {
	GLfloat mat_specular[] = { r, g, b, a };
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
}

void setMatShineness(float shine) {
	GLfloat mat_shininess[] = { shine };
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

/*--------------------------------------------------------------------
Draws the x, y and z axis
--------------------------------------------------------------------*/
void drawAxis() {
	glBegin(GL_LINES);
			glColor3f(0, 1, 0);
			/*setMatAmbientColor(0, 1, 0, 1);
			setMatDiffuseColor(0, 1, 0, 1);
			setMatSpecularColor(0, 1, 0, 1);*/
		//Y axis
		glVertex3f(0, -1000, -20);
		glVertex3f(0,  1000, -20);

		//X axis
			glColor3f(0, 0, 1);
			/*setMatAmbientColor(0, 0, 1, 1);
			setMatDiffuseColor(0, 0, 1, 1);
			setMatSpecularColor(0, 0, 1, 1);*/
		glVertex3f(-1000, 0, -20);
		glVertex3f( 1000, 0, -20);
		
		//Z axis
			glColor3f(1, 0, 0);
			/*setMatAmbientColor(1, 0, 0, 1);
			setMatDiffuseColor(1, 0, 0, 1);
			setMatSpecularColor(1, 0, 0, 1);*/
		glVertex3f( 0, 0, -1000);
		glVertex3f( 0, 0, 1000);
	glEnd();
}

/*--------------------------------------------------------------------
Calculates normal for given four points
--------------------------------------------------------------------*/
void drawWater()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,water);
	glNormal3f(0,1.0,0.0);
	glBegin(GL_QUADS);
	
	glTexCoord2f(0,0);glVertex3f(-1000,1000, -20);
	glTexCoord2f(1,0);glVertex3f(-1000, -1000, -20);
	glTexCoord2f(1,1);glVertex3f(1000, -1000, -20);
	glTexCoord2f(0,1);glVertex3f( 1000, 1000, -20);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void r3CalculateVertexAndNormalForRectangle(M3DVector3f v1, M3DVector3f v2, M3DVector3f v3, M3DVector3f v4) {
	M3DVector3f normal;

	m3dFindNormal(normal, v1, v2, v3);
	m3dNormalizeVector(normal);
	glNormal3f(normal[0], normal[1], normal[2]);
	m3dFindNormal(normal, v2, v3, v4);
	m3dNormalizeVector(normal);
	glNormal3f(normal[0], normal[1], normal[2]);
	glColor3f(0,0,0);
	glTexCoord2f(0,0);glVertex3f(v1[0], v1[1], v1[2]);
	glTexCoord2f(1,0);glVertex3f(v2[0], v2[1], v2[2]);
	glTexCoord2f(1,1);glVertex3f(v3[0], v3[1], v3[2]);
	glTexCoord2f(0,1);glVertex3f(v4[0], v4[1], v4[2]);
}

/*--------------------------------------------------------------------
l for length, w for width and H for height
d for difference betn lower and upper rectangle
upper rectangle is smaller than lower
diffrence ratio is same on all side
--------------------------------------------------------------------*/
void r3drawRectangle(float l, float w, float H, float d,GLuint temp) {
	M3DVector3f v1, v2, v3, v4;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,temp);
	glNormal3f(0,1.0,0.0);
	glBegin(GL_QUADS);
		v1[0] = l * 0,	v1[1] = w * 0,	v1[2] = 0;
		v2[0] = l * 10, v2[1] = w * 0,	v2[2] = 0;
		v3[0] = l * 10, v3[1] = w * 10,	v3[2] = 0;
		v4[0] = l * 0,	v4[1] = w * 10,	v4[2] = 0;
		r3CalculateVertexAndNormalForRectangle(v4, v3, v2, v1);

		v1[0] = l * d,		  v1[1] = w * d,		v1[2] = H;
		v2[0] = l * (10 - d), v2[1] = w * d,		v2[2] = H;
		v3[0] = l * (10 - d), v3[1] = w * (10 - d),	v3[2] = H;
		v4[0] = l * d,		  v4[1] = w * (10 - d),	v4[2] = H;
		r3CalculateVertexAndNormalForRectangle(v1, v2, v3, v4);

		v1[0] = l * 0, v1[1] = w * 10,		 v1[2] = 0;
		v2[0] = l * 0, v2[1] = w * 0,		 v2[2] = 0;
		v3[0] = l * d, v3[1] = w * d,		 v3[2] = H;
		v4[0] = l * d, v4[1] = w * (10 - d), v4[2] = H;
		r3CalculateVertexAndNormalForRectangle(v1, v2, v3, v4);

		v1[0] = l * 10,		  v1[1] = w * 0,		v1[2] = 0;
		v2[0] = l * 10,		  v2[1] = w * 10,		v2[2] = 0;
		v3[0] = l * (10 - d), v3[1] = w * (10 - d),	v3[2] = H;
		v4[0] = l * (10 - d), v4[1] = w * d,		v4[2] = H;
		r3CalculateVertexAndNormalForRectangle(v4, v3, v2, v1);

		v1[0] = l * 0,		  v1[1] = w * 0, v1[2] = 0;
		v2[0] = l * 10,		  v2[1] = w * 0, v2[2] = 0;
		v3[0] = l * (10 - d), v3[1] = w * d, v3[2] = H;
		v4[0] = l * d,		  v4[1] = w * d, v4[2] = H;
		r3CalculateVertexAndNormalForRectangle(v1, v2, v3, v4);

		v1[0] = l * 0,			v1[1] = w * 10,	   	  v1[2] = 0;
		v2[0] = l * 10,			v2[1] = w * 10,		  v2[2] = 0;
		v3[0] = l * (10 - d),	v3[1] = w * (10 - d), v3[2] = H;
		v4[0] = l * d,			v4[1] = w * (10 - d), v4[2] = H;
		r3CalculateVertexAndNormalForRectangle(v4, v3, v2, v1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void r2UpCircleGate(float x, float y, float z, float up, float height, int N) {
	float angle;
	M3DVector3f v1, v2, v3, norm;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,upPiller);
	glNormal3f(0,1.0,0.0);
	
	glBegin(GL_TRIANGLE_STRIP);
		for(int i = 0; i <= N; ++i) {
			angle = PI * i / N;
			if(i > 0) {
				v3[0] = x + cos(angle) * up;
				v3[1] = y + sin(angle) * up;
				v3[2] = z;

				m3dFindNormal(norm, v1, v2, v3);
				m3dNormalizeVector(norm);
				glNormal3f(norm[0], norm[1], norm[2]);
			}
			v1[0] = x + cos(angle) * up;
			v1[1] = y + sin(angle) * up;
			v1[2] = z;
			v2[0] = x + cos(angle) * up;
			v2[1] = y + height;
			v2[2] = z;
					
			glVertex3f(v1[0], v1[1], v1[2]);
			glVertex3f(v2[0], v2[1], v2[2]);
		}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void r2Ring(float x, float y, float z, float up, float down, float width, int N, int dim) {
	float angle;
	M3DVector3f ver1, ver2, ver3, normal;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,arc);
	glNormal3f(0,1.0,0.0);
	
	glBegin(GL_TRIANGLE_STRIP);
		for(int i = 0; i <= N; ++i) {
			angle = dim * PI * i / N;
			if(i > 0) {
				ver3[0] = x + cos(angle) * up;
				ver3[1] = y + sin(angle) * up;
				ver3[2] = z;

				m3dFindNormal(normal, ver3, ver2, ver1);
				m3dNormalizeVector(normal);
				glNormal3f(normal[0], normal[1], normal[2]);
			}
			ver1[0] = x + cos(angle) * up;
			ver1[1] = y + sin(angle) * up;
			ver1[2] = z;
			ver2[0] = x + cos(angle) * down;
			ver2[1] = y + sin(angle) * down;
			ver2[2] = z + width;
					
			glVertex3f(ver1[0], ver1[1], ver1[2]);
			glVertex3f(ver2[0], ver2[1], ver2[2]);
		}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void lowerPiller(float x, float y, float z) {
	glEnable(GL_NORMALIZE);

		glScalef(x, y, z);

		glPushMatrix();
			r3drawRectangle(5, 5, 20, 2,lowPiller);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(6.6, 6.6, 25);
			r3drawRectangle(3.7, 3.7, -5, 1,lowPiller);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(6.6, 6.6, 25);
			r3drawRectangle(3.7, 3.7, 5, 1,lowPiller);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(10, 10, 30);
			r3drawRectangle(3, 3, 20, 1,lowPiller);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(13, 13, 50);
			r3drawRectangle(2.4, 2.4, 20, 0,lowPiller);
		glPopMatrix();

	glDisable(GL_NORMALIZE);
}

void r3SideGate(bool bottom = true) {
	glPushMatrix();
		r2UpCircleGate(0, 0, 0, 10, 15, 20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, 0, 10);
		glRotatef(180, 0, 1, 0);
		r2UpCircleGate(0, 0, 0, 10, 15, 20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(10, -30, 0);
		r3drawRectangle(0.65, 4.5, 10, 0,upPiller);
		glPushMatrix();
		glTranslatef(-26.5, 0, 0);
			r3drawRectangle(0.65, 4.5, 10, 0,upPiller);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-10, -30, 0);
		r3drawRectangle(2, 0.65, 10, 0,upPiller);
	glPopMatrix();

	if(bottom) {
		glPushMatrix();
			glTranslatef(-10, 15, 0);
			r3drawRectangle(2, 0.0025, 10, 0,upPiller);
		glPopMatrix();
	}

	r2Ring(0, 0, 0, 10, 10, 10, 25, 1);
}

void r3FrontGate() {
	glEnable(GL_NORMALIZE);
		glPushMatrix();
		glTranslatef(34, 69, 79);
		glRotatef(90, 1, 0, 0);
		glRotatef(90, 0, 1, 0);
			glScalef(.3, .3, .3);
			r3SideGate();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(34, 31, 79);
		glRotatef(90, 1, 0, 0);
		glRotatef(90, 0, 1, 0);
			glScalef(.3, .3, .3);
			r3SideGate();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(31, 50, 86);
		glRotatef(90, 1, 0, 0);
		glRotatef(90, 0, 1, 0);
			glScalef(.9, .7, .3);
			r3SideGate();
		glPopMatrix();
	glDisable(GL_NORMALIZE);

	glPushMatrix();
	glTranslatef(34.2, 26, 102);
	glRotatef(90, 0, 1, 0);
		r3drawRectangle(1.9, 1, 2.8, 0,upPiller);
	glPopMatrix();
		
	glPushMatrix();
	glTranslatef(34.2, 64, 102);
	glRotatef(90, 0, 1, 0);
		r3drawRectangle(1.9, 1, 2.8, 0,upPiller);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(34.2, 36, 102);
	glRotatef(90, 0, 1, 0);
		r3drawRectangle(.6, 2.8, 2.8, 0,upPiller);
	glPopMatrix();
}

void bigPiller() {
		glColor3f(1, 0, 0);
		/*setMatAmbientColor(1, 0, 0, 1);
		setMatDiffuseColor(1, 0, 0, 1);
		setMatSpecularColor(1, 0, 0, 1);*/
	glPushMatrix();
		lowerPiller(1, 2, 1);
	glPopMatrix();

			glEnable(GL_NORMALIZE);

		glColor3f(0, 1, 0);
		/*setMatAmbientColor(0, 1, 0, 1);
		setMatDiffuseColor(0, 1, 0, 1);
		setMatSpecularColor(0, 1, 0, 1);*/
	glPushMatrix();
	glTranslatef(25, 27.9, 91);
	glRotatef(90, 1, 0, 0);
		glScalef(0.72, 0.7, 0.2);
		r3SideGate();

			

		glPushMatrix();
		glTranslatef(0, 0, -221);
		glRotatef(180, 0, 1, 0);
			r3SideGate();
		glPopMatrix();
	glPopMatrix();
	glDisable(GL_NORMALIZE);

		//glColor3f(0.5, 1, 1);
		/*setMatAmbientColor(0.5, 1, 1, 1);
		setMatDiffuseColor(0.5, 1, 1, 1);
		setMatSpecularColor(0.5, 1, 1, 1);*/
	glPushMatrix();
		r3FrontGate();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(50, 100, 0);
	glRotatef(180, 0, 0, 1);
		r3FrontGate();
	glPopMatrix();

		glColor3f(1, 1, 1);
		/*setMatAmbientColor(1, 1, 1, 1);
		setMatDiffuseColor(1, 1, 1, 1);
		setMatSpecularColor(1, 1, 1, 1);*/
	glPushMatrix();
	glTranslatef(8, 20, 106);
		r3drawRectangle(3.3, 6, -5, 1,upPiller);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8, 20, 106);
		r3drawRectangle(3.3, 6, 6, 0,upPiller);
	glPopMatrix();
}

void smallPiller() {
	glColor3f(0, 0, 0);
	glPushMatrix();
		glTranslatef(-20, -10, 15);
		r3drawRectangle(4.1, 1, 10, 0,lowPiller);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-25.2, -20, -30);
		r3drawRectangle(1.5, 3, 45, 3.4,lowPiller);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(11, -20, -30);
		r3drawRectangle(1.5, 3, 45, 3.4,lowPiller);
	glPopMatrix();

	glPushMatrix();
		glRotatef(90, 1, 0, 0);
		r3SideGate(false);
	glPopMatrix();
}

void r2FlatCircle(float x, float y, float z, float rad, float width, int N) {
	float angle;
	M3DVector3f v1, v2, v3, norm;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,arc);
	glNormal3f(0,1.0,0.0);
	glBegin(GL_TRIANGLE_STRIP);
		for(int i = 0; i <= N; ++i) {
			angle = 2 * PI * i / N;
			if(i > 0) {
				v3[0] = x + cos(angle) * rad;
				v3[1] = y + sin(angle) * rad;
				v3[2] = z;

				m3dFindNormal(norm, v1, v2, v3);
				m3dNormalizeVector(norm);
				glNormal3f(norm[0], norm[1], norm[2]);
			}
			v1[0] = x + cos(angle) * rad;
			v1[1] = y + sin(angle) * rad;
			v1[2] = z;
			v2[0] = x + cos(angle) * (rad + width);
			v2[1] = y + sin(angle) * (rad + width);
			v2[2] = z;
					
			glVertex3f(v1[0], v1[1], v1[2]);
			glVertex3f(v2[0], v2[1], v2[2]);
		}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void r3Ring(float rad, float d, int N1, int N2) {
	N1 += 24;
	N2 += 24;

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
		r2Ring(0,0,0,	rad, rad, d, N1, 2);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
		r2FlatCircle(0, 0, 0, rad - d, d, N2);
		glPushMatrix();
		glTranslatef(0, 0, d);
			r2FlatCircle(0, 0, 0, rad - d, d, N2);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
		r2Ring(0,0,0,	rad - d, rad - d, d, N1, 2);
	glPopMatrix();
}

void bridgeLowerArch(float clip, int N) {
	GLdouble eqn0[] = {0, 0, 1, -clip};
	GLdouble eqn1[] = {0, -1, 0, 0};

	glPushMatrix();
	glTranslatef(0, 0, -clip);
	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_CLIP_PLANE1);

	glClipPlane(GL_CLIP_PLANE0, eqn0);
	glClipPlane(GL_CLIP_PLANE1, eqn1);
		r3Ring(200, 3, N, 50);
	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);
	glPopMatrix();
}
//
void bridgeUpperArch(float clip, int N) {
	GLdouble eqn0[] = {0, 0, 1, -clip};
	GLdouble eqn1[] = {0, -1, 0, 0};

	glPushMatrix();
	glTranslatef(0, 0, -clip);
	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_CLIP_PLANE1);

	glClipPlane(GL_CLIP_PLANE0, eqn0);
	glClipPlane(GL_CLIP_PLANE1, eqn1);
		r3Ring(220, 3, N, 50);
	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);
	glPopMatrix();
}

void smallerArch(int N) {
	GLdouble eqn0[] = {0, 0, -1, -190};
	GLdouble eqn1[] = {0, 1, 0, 21};
	GLdouble eqn2[] = {0, -1, 0, 24};

	glPushMatrix();
	glRotatef(20, 1, 0, 0);
	glTranslatef(0, 0, 190);
	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_CLIP_PLANE1);
	glEnable(GL_CLIP_PLANE2);

	glClipPlane(GL_CLIP_PLANE0, eqn0);
	glClipPlane(GL_CLIP_PLANE1, eqn1);
	glClipPlane(GL_CLIP_PLANE2, eqn2);
		r3Ring(200, 3, N, 50);
	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);
	glDisable(GL_CLIP_PLANE2);
	glPopMatrix();
}

void drawBridgeArch() {
	glPushMatrix();
	glTranslatef(20, 250, -10);
			glColor3f(0.5, 1, 1);
			/*setMatAmbientColor(0.5, 1, 1, 1);
			setMatDiffuseColor(0.5, 1, 1, 1);
			setMatSpecularColor(0.5, 1, 1, 1);*/
		bridgeLowerArch(140, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(20, 127, 45);
		smallerArch(100);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(20, 250, 45.5);
		bridgeUpperArch(194, 100);
	glPopMatrix();
}

void verticalBeams() {
	float x, y, z;
	x = 22, y = 245, z = 49;
	for(int i = 0; i < 3; i++) {
		glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(90, 0, 0, 1);
			r3drawRectangle(0.3, 0.01, 22, 0,arc);
		glPopMatrix();
		z -= 4;
		y -= 25;
	}

	x = 22, y = 165, z = 31;
	for(int i = 0; i < 2; i++) {
		glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(90, 0, 0, 1);
			r3drawRectangle(0.3, 0.01, 23, 0,arc);
		glPopMatrix();
		z -= 13.5;
		y -= 25;
	}

	glPushMatrix();
		glTranslatef(22, 115, -2);
		glRotatef(90, 0, 0, 1);
			r3drawRectangle(0.3, 0.01, 35, 0,arc);
	glPopMatrix();
}

void angularBeams() {
	float x = 22, y = 222, z = 49;
	for(int i = 0; i < 2; i++) {
		glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(-45, 1, 0, 0);
		glRotatef(90, 0, 0, 1);
			r3drawRectangle(0.3, 0.01, 32, 0,arc);
		glPopMatrix();

		z -= 4;
		y -= 25;
	}

	glPushMatrix();
		glTranslatef(22, 167, 34);
		glRotatef(-45, 1, 0, 0);
		glRotatef(90, 0, 0, 1);
			r3drawRectangle(0.3, 0.01, 42, 0,arc);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(22, 142, 20);
		glRotatef(-35, 1, 0, 0);
		glRotatef(90, 0, 0, 1);
			r3drawRectangle(0.3, 0.01, 42, 0,arc);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(22, 117, 1);
		glRotatef(-30, 1, 0, 0);
		glRotatef(90, 0, 0, 1);
			r3drawRectangle(0.3, 0.01, 47, 0,arc);
	glPopMatrix();
}

void verticalWires() {
		glColor3f(0, 0.5, 1);
		/*setMatAmbientColor(0, 0.5, 1, 1);
		setMatDiffuseColor(0, 0.5, 1, 1);
		setMatSpecularColor(0, 0.5, 1, 1);*/
	float y = 235, length = 29;
	for(int i = 0; i < 3; i++) {
		glPushMatrix();
		glTranslatef(22, y, 18);
		glRotatef(90, 0, 0, 1);
			r3drawRectangle(0.1, 0.1, length, 0,arc);
		glPopMatrix();
		length -= 4;
		y -= 25;
	}
}

void halfBridge() {
	glTranslatef(0, -200, 0);

	glEnable(GL_NORMALIZE);

		glPushMatrix();
		glTranslatef(47, 90, -30);
		glRotatef(90, 0, 0, 1);
			glScalef(0.6, 0.9, 0.7);
			bigPiller();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(3, 0, -2);
		glScalef(0.7, 1, 0.8);
			smallPiller();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(3, -90, -2);
		glScalef(0.7, 1, 0.8);
			smallPiller();
		glPopMatrix();

	glDisable(GL_NORMALIZE);

	drawBridgeArch();
	verticalBeams();
	angularBeams();
	verticalWires();

	glPushMatrix();
	glTranslatef(-35, 0, 0);
		drawBridgeArch();
		verticalBeams();
		angularBeams();
		verticalWires();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-13.5, -118, 17.1);
			glColor3f(0.8, 0.3, 0.8);
		/*	setMatAmbientColor(0.8, 0.3, 0.8, 1);
			setMatDiffuseColor(0.8, 0.3, 0.8, 1);
			setMatSpecularColor(0.8, 0.3, 0.8, 1);*/
		r3drawRectangle(3.5, 37, 2, 0,railLine);
	glPopMatrix();
}

void fullBridge() {

	glPushMatrix();
		drawWater();
	glPopMatrix();
	
	glPushMatrix();
		halfBridge();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8, 92, 0);
	glRotatef(180, 0, 0, 1);
		halfBridge();
	glPopMatrix();
}