#include "Texture.h"

float Rs = 15.0f;//size of room
float Tw = 2.0f;// width of table top from centre
float Tl = 4.0f; //length of table top from centre
float Th = 1.7f; //height of table top from centre
float Tt = 0.3f;//thickness of table top
float Ls = 0.3f;//size of table leg

float Bw = 2.0f / 3.0f;// width of book from centre
float Bl = 4.0f / 3.0f; //length of book from centre
float Bh = 2.0f; //height of book from centre
float Bt = 0.025f;//thickness of book cover
float Btt = 0.1f;//thickness of books 1 and 2
float Btt3 = 0.13f;//thickness of book 3
float Bb = 0.03f;//thickness of binding
float ang1 = 5.0f;//rotation of book1
float B2h = Bt + Btt;// height of book2
float B3h = 2 * B2h;// height of book3
float ang2 = 30.0f;//rotation of book2
float ang3 = 190.0f;//rotation of book3

float a = 0.0f;// position for cube
float b = 0.0f;
float c = 0.0f;
float d = 1.5f;//size of cube
float min = 0.0f;
float max = 1.0f;
float wll = 0.01f;

void drwatableTop()
{
	glPushMatrix();// 1 set where to start the current object transformation
	glTranslatef(0.0f, -2.0f, 0.0f);// move downwards to lie on the floor

	glBegin(GL_QUADS);
	// bottom: normal pointing outwards
//	glNormal3f(0, 1, 0);
	//glNormal3f(0, -1, 0);
	glTexCoord2f(min, min);
	glVertex3f(-Tw, Th, Tl);
	glTexCoord2f(max, min);
	glVertex3f(-Tw, Th, -Tl);
	glTexCoord2f(max, max);
	glVertex3f(Tw, Th, -Tl);
	glTexCoord2f(min, max);
	glVertex3f(Tw, Th, Tl);
	//Top:normal pointing outwards

	//front:normal pointing outwards
	//glNormal3f(0, 0, 1);
	glTexCoord2f(min, min);
	glVertex3f(-Tw, Th + Tt, Tl);
	glTexCoord2f(max, min);
	glVertex3f(-Tw, Th, Tl);
	glTexCoord2f(max, max);
	glVertex3f(Tw, Th, Tl);
	glTexCoord2f(min, max);
	glVertex3f(Tw, Th + Tt, Tl);
	//back:normal pointing outwards
	//glNormal3f(0, 0, -1);
	glTexCoord2f(min, min);
	glVertex3f(Tw, Th + Tt, -Tl);
	glTexCoord2f(max, min);
	glVertex3f(Tw, Th, -Tl);
	glTexCoord2f(max, max);
	glVertex3f(-Tw, Th, -Tl);
	glTexCoord2f(min, max);
	glVertex3f(-Tw, Th + Tt, -Tl);
	//right:normal pointing outwards
	//glNormal3f(1, 0, 0);
	glTexCoord2f(min, min);
	glVertex3f(Tw, Th + Tt, Tl);
	glTexCoord2f(max, min);
	glVertex3f(Tw, Th, Tl);
	glTexCoord2f(max, max);
	glVertex3f(Tw, Th, -Tl);
	glTexCoord2f(min, max);
	glVertex3f(Tw, Th + Tt, -Tl);
	//left:normal pointing outwards
	//glNormal3f(-1, 0, 0);
	glTexCoord2f(max, max);
	glVertex3f(-Tw, Th + Tt, Tl);
	glTexCoord2f(min, max);
	glVertex3f(-Tw, Th + Tt, -Tl);
	glTexCoord2f(min, min);
	glVertex3f(-Tw, Th, -Tl);
	glTexCoord2f(max, min);
	glVertex3f(-Tw, Th, Tl);

	//top
	//glNormal3f(0, 1, 0);
	glTexCoord2f(min, min);
	glVertex3f(-Tw, Th + Tt, Tl);
	glTexCoord2f(min, max);
	glVertex3f(Tw, Th + Tt, Tl);
	glTexCoord2f(max, max);
	glVertex3f(Tw, Th + Tt, -Tl);
	glTexCoord2f(max, min);
	glVertex3f(-Tw, Th + Tt, -Tl);
	glEnd();
	glPopMatrix();
}
void Firstleg()
{
	glPushMatrix();// 1 set where to start the current object transformation
	glTranslatef(0.0f, -2.0f, 0.0f);// move downwards to lie on the floor

	glBegin(GL_QUADS);
	// front:normal pointing outwards
	glNormal3f(0, 0, 1);
	glTexCoord2f(min, min);
	glVertex3f(-Tw + Ls, Th, Tl - Ls);
	glTexCoord2f(max, min);
	glVertex3f(-Tw + Ls, 0.0f, Tl - Ls);
	glTexCoord2f(max, max);
	glVertex3f(-Tw + Ls + Ls, 0.0f, Tl - Ls);
	glTexCoord2f(min, max);
	glVertex3f(-Tw + Ls + Ls, Th, Tl - Ls);
	//back:normal pointing outwards
	glNormal3f(0, 0, -1);
	glTexCoord2f(1, 1);
	glVertex3f(-Tw + Ls, Th, Tl - Ls - Ls);
	glTexCoord2f(0, 1);
	glVertex3f(-Tw + Ls + Ls, Th, Tl - Ls - Ls);
	glTexCoord2f(0, 0);
	glVertex3f(-Tw + Ls + Ls, 0.0f, Tl - Ls - Ls);
	glTexCoord2f(1, 0);
	glVertex3f(-Tw + Ls, 0.0f, Tl - Ls - Ls);
	//right: normal pointing outwards
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 1);
	glVertex3f(-Tw + Ls + Ls, Th, Tl - Ls);
	glTexCoord2f(0, 0);
	glVertex3f(-Tw + Ls + Ls, 0.0f, Tl - Ls);
	glTexCoord2f(1, 0);
	glVertex3f(-Tw + Ls + Ls, 0.0f, Tl - Ls - Ls);
	glTexCoord2f(1, 1);
	glVertex3f(-Tw + Ls + Ls, Th, Tl - Ls - Ls);
	//left:normal pointing outwards
	glNormal3f(-1, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(-Tw + Ls, Th, Tl - Ls);
	glTexCoord2f(0, 1);
	glVertex3f(-Tw + Ls, Th, Tl - Ls - Ls);
	glTexCoord2f(0, 0);
	glVertex3f(-Tw + Ls, 0.0f, Tl - Ls - Ls);
	glTexCoord2f(1, 0);
	glVertex3f(-Tw + Ls, 0.0f, Tl - Ls);

	glEnd();
	glPopMatrix();
}
void secondleg()
{
	glPushMatrix();// 1 set where to start the current object transformation
	glTranslatef(0.0f, -2.0f, 0.0f);// move downwards to lie on the floor

	glBegin(GL_QUADS);
	//front:Normals pointing outwards
	glNormal3f(0, 0, 1);
	glTexCoord2f(1, 1);
	glVertex3f(Tw - Ls, Th, Tl - Ls);
	glTexCoord2f(0, 1);
	glVertex3f(Tw - Ls - Ls, Th, Tl - Ls);
	glTexCoord2f(0, 0);
	glVertex3f(Tw - Ls - Ls, 0.0f, Tl - Ls);
	glTexCoord2f(1, 0);
	glVertex3f(Tw - Ls, 0.0f, Tl - Ls);

	//back:normals pointing outwards
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 1);
	glVertex3f(Tw - Ls, Th, Tl - Ls - Ls);
	glTexCoord2f(0, 0);
	glVertex3f(Tw - Ls, 0.0f, Tl - Ls - Ls);
	glTexCoord2f(1, 0);
	glVertex3f(Tw - Ls - Ls, 0.0f, Tl - Ls - Ls);
	glTexCoord2f(1, 1);
	glVertex3f(Tw - Ls - Ls, Th, Tl - Ls - Ls);
	//left:normal pointing outwards
	glNormal3f(-1, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(Tw - Ls - Ls, Th, Tl - Ls);
	glTexCoord2f(0, 1);
	glVertex3f(Tw - Ls - Ls, Th, Tl - Ls - Ls);
	glTexCoord2f(0, 0);
	glVertex3f(Tw - Ls - Ls, 0.0f, Tl - Ls - Ls);
	glTexCoord2f(1, 0);
	glVertex3f(Tw - Ls - Ls, 0.0f, Tl - Ls);
	//right:normal pointing outwards
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 1);
	glVertex3f(Tw - Ls, Th, Tl - Ls);
	glTexCoord2f(0, 0);
	glVertex3f(Tw - Ls, 0.0f, Tl - Ls);
	glTexCoord2f(1, 0);
	glVertex3f(Tw - Ls, 0.0f, Tl - Ls - Ls);
	glTexCoord2f(1, 1);
	glVertex3f(Tw - Ls, Th, Tl - Ls - Ls);
	glEnd();
	glPopMatrix();
}
void thirdleg()
{
	glPushMatrix();// 1 set where to start the current object transformation
	glTranslatef(0.0f, -2.0f, 0.0f);// move downwards to lie on the floor

	glBegin(GL_QUADS);
	//front:normal pointing outwards
	glNormal3f(0, 0, 1);
	glTexCoord2f(min, min);
	glVertex3f(-Tw + Ls, Th, -Tl + Ls);
	glTexCoord2f(max, min);
	glVertex3f(-Tw + Ls, 0.0f, -Tl + Ls);
	glTexCoord2f(max, max);
	glVertex3f(-Tw + Ls + Ls, 0.0f, -Tl + Ls);
	glTexCoord2f(min, max);
	glVertex3f(-Tw + Ls + Ls, Th, -Tl + Ls);
	//back:normal pointing outwards
	glNormal3f(0, 0, -1);
	glTexCoord2f(1, 1);
	glVertex3f(-Tw + Ls, Th, -Tl + Ls + Ls);
	glTexCoord2f(0, 1);
	glVertex3f(-Tw + Ls + Ls, Th, -Tl + Ls + Ls);
	glTexCoord2f(0, 0);
	glVertex3f(-Tw + Ls + Ls, 0.0f, -Tl + Ls + Ls);
	glTexCoord2f(1, 0);
	glVertex3f(-Tw + Ls, 0.0f, -Tl + Ls + Ls);
	//right: normal pointing outwards
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 1);
	glVertex3f(-Tw + Ls + Ls, Th, -Tl + Ls);
	glTexCoord2f(0, 0);
	glVertex3f(-Tw + Ls + Ls, 0.0f, -Tl + Ls);
	glTexCoord2f(1, 0);
	glVertex3f(-Tw + Ls + Ls, 0.0f, -Tl + Ls + Ls);
	glTexCoord2f(1, 1);
	glVertex3f(-Tw + Ls + Ls, Th, -Tl + Ls + Ls);
	//left:normal pointing outwards
	glNormal3f(-1, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(-Tw + Ls, Th, -Tl + Ls);
	glTexCoord2f(0, 1);
	glVertex3f(-Tw + Ls, Th, -Tl + Ls + Ls);
	glTexCoord2f(0, 0);
	glVertex3f(-Tw + Ls, 0.0f, -Tl + Ls + Ls);
	glTexCoord2f(1, 0);
	glVertex3f(-Tw + Ls, 0.0f, -Tl + Ls);
	glEnd();
	glPopMatrix();
}
void fourthleg()
{
	glPushMatrix();// 1 set where to start the current object transformation
	glTranslatef(0.0f, -2.0f, 0.0f);// move downwards to lie on the floor

	glBegin(GL_QUADS);
	//front:Normals pointing outwards
	glNormal3f(0, 0, 1);
	glTexCoord2f(1, 1);
	glVertex3f(Tw - Ls, Th, -Tl + Ls);
	glTexCoord2f(0, 1);
	glVertex3f(Tw - Ls - Ls, Th, -Tl + Ls);
	glTexCoord2f(0, 0);
	glVertex3f(Tw - Ls - Ls, 0.0f, -Tl + Ls);
	glTexCoord2f(1, 0);
	glVertex3f(Tw - Ls, 0.0f, -Tl + Ls);
	//back:normals pointing outwards
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 1);
	glVertex3f(Tw - Ls, Th, -Tl + Ls + Ls);
	glTexCoord2f(0, 0);
	glVertex3f(Tw - Ls, 0.0f, -Tl + Ls + Ls);
	glTexCoord2f(1, 0);
	glVertex3f(Tw - Ls - Ls, 0.0f, -Tl + Ls + Ls);
	glTexCoord2f(1, 1);
	glVertex3f(Tw - Ls - Ls, Th, -Tl + Ls + Ls);
	//left:normal pointing outwards
	glNormal3f(-1, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(Tw - Ls - Ls, Th, -Tl + Ls);
	glTexCoord2f(0, 1);
	glVertex3f(Tw - Ls - Ls, Th, -Tl + Ls + Ls);
	glTexCoord2f(0, 0);
	glVertex3f(Tw - Ls - Ls, 0.0f, -Tl + Ls + Ls);
	glTexCoord2f(1, 0);
	glVertex3f(Tw - Ls - Ls, 0.0f, -Tl + Ls);
	//right:normal pointing outwards
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 1);
	glVertex3f(Tw - Ls, Th, -Tl + Ls);
	glTexCoord2f(0, 0);
	glVertex3f(Tw - Ls, 0.0f, -Tl + Ls);
	glTexCoord2f(1, 0);
	glVertex3f(Tw - Ls, 0.0f, -Tl + Ls + Ls);
	glTexCoord2f(1, 1);
	glVertex3f(Tw - Ls, Th, -Tl + Ls + Ls);
	glEnd();
	glPopMatrix();
}
void dglasscube()
{
	glPushMatrix();

	glTranslatef(0.3f, 0.0f, -2.3f);
	glBegin(GL_QUADS);//line loop wchich automatically connects the dots
	//front: normal pointing outwards
	glTexCoord2f(0, 0);
	glVertex3f(a, b, c);
	glTexCoord2f(1, 0);
	glVertex3f(a + d, b, c);
	glTexCoord2f(1, 1);
	glVertex3f(a + d, b + d, c);
	glTexCoord2f(0, 1);
	glVertex3f(a, b + d, c);

	//right:normal pointing outwards
	glTexCoord2f(min, min);
	glVertex3f(a + d, b, c);
	glTexCoord2f(max, min);
	glVertex3f(a + d, b, c - d);
	glTexCoord2f(max, max);
	glVertex3f(a + d, b + d, c - d);
	glTexCoord2f(min, max);
	glVertex3f(a + d, b + d, c);
	//back:normal pointing outwards 
	glTexCoord2f(min, min);
	glVertex3f(a + d, b, c - d);
	glTexCoord2f(max, min);
	glVertex3f(a, b, c - d);
	glTexCoord2f(max, max);
	glVertex3f(a, b + d, c - d);
	glTexCoord2f(min, max);
	glVertex3f(a + d, b + d, c - d);
	//left:normal pointing outwards
	glTexCoord2f(min, min);
	glVertex3f(a, b, c - d);
	glTexCoord2f(max, min);
	glVertex3f(a, b, c);
	glTexCoord2f(max, max);
	glVertex3f(a, b + d, c);
	glTexCoord2f(min, max);
	glVertex3f(a, b + d, c - d);
	//top: normal pointing outwards
	glTexCoord2f(min, min);
	glVertex3f(a, b + d, c);
	glTexCoord2f(max, min);
	glVertex3f(a + d, b + d, c);
	glTexCoord2f(max, max);
	glVertex3f(a + d, b + d, c - d);
	glTexCoord2f(min, max);
	glVertex3f(a, b + d, c - d);
	//bottom:normal pointing outwards 
	glTexCoord2f(min, min);
	glVertex3f(a, b, c);
	glTexCoord2f(min, max);
	glVertex3f(a, b, c - d);
	glTexCoord2f(max, max);
	glVertex3f(a + d, b, c - d);
	glTexCoord2f(max, min);
	glVertex3f(a + d, b, c);

	glEnd();
	glPopMatrix();
}

void bk1()
{

	glPushMatrix(); //2
	glTranslatef(-1.0f, -2.0f, 2.0f);// move to lie on the left corner of the table
	glRotatef(ang1, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	/////////////bottom cover///
	// bottom
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh, Bl);
	//Top
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh + Bt, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, Bl);
	//front
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, Bl);
	//back
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, -Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	//right
	glTexCoord2f(min, min);
	glVertex3f(Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	//left
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw, Bh + Bt, -Bl);

	glEnd();
	glPopMatrix();//2 

	///////////////top cover////////
	glPushMatrix(); //3
	glTranslatef(-1.0f, -2.0f + Btt, 2.0f);// move up to lie above bottom cover
	glRotatef(ang1, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	// bottom
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh, Bl);
	//front
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, Bl);
	//back
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, -Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	//right
	glTexCoord2f(min, min);
	glVertex3f(Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	//left
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw, Bh + Bt, -Bl);

	glEnd();
	glPopMatrix();  //3
	////////////////////binding//////
	glPushMatrix();//5
	glTranslatef(-1.0f, -2.0f, 2.0f);
	glRotatef(ang1, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);

	//front
	glTexCoord2f(min, min);
	glVertex3f(-Bw - Bb, Bh, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh + Bt + Btt, Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt, Bl);
	//back
	glTexCoord2f(min, min);
	glVertex3f(-Bw - Bb, Bh, -Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh + Bt + Btt, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt, -Bl);
	//left
	glTexCoord2f(min, min);
	glVertex3f(-Bw - Bb, Bh, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw - Bb, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt, Bl);
	//right
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh + Bt + Btt, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw, Bh + Bt + Btt, Bl);
	//top
	glTexCoord2f(min, min);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh + Bt + Btt, Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh + Bt + Btt, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt, -Bl);
	glEnd();
	//glDisable(GL_TEXTURE_2D);
	glPopMatrix();//5
}
void bk2()
{
	glPushMatrix(); //2
	glTranslatef(-1.0f, -2.0f + B2h, 2.0f);// move to lie on the left corner of the table
	glRotatef(ang2, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	/////////////bottom cover///
	// bottom
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh, Bl);
	//Top
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh + Bt, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, Bl);
	//front
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, Bl);
	//back
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, -Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	//right
	glTexCoord2f(min, min);
	glVertex3f(Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	//left
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw, Bh + Bt, -Bl);

	glEnd();
	glPopMatrix();//2 

	///////////////top cover////////
	glPushMatrix(); //3
	glTranslatef(-1.0f, -2.0f + B2h + Btt, 2.0f);// move up to lie above bottom cover
	glRotatef(ang2, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	// bottom
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh, Bl);
	//front
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, Bl);
	//back
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, -Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	//right
	glTexCoord2f(min, min);
	glVertex3f(Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	//left
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw, Bh + Bt, -Bl);

	glEnd();
	glPopMatrix();  //3
	////////////////////binding//////
	glPushMatrix();//5
	glTranslatef(-1.0f, -2.0f + B2h, 2.0f);
	glRotatef(ang2, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);

	//front
	glTexCoord2f(min, min);
	glVertex3f(-Bw - Bb, Bh, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh + Bt + Btt, Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt, Bl);
	//back
	glTexCoord2f(min, min);
	glVertex3f(-Bw - Bb, Bh, -Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh + Bt + Btt, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt, -Bl);
	//left
	glTexCoord2f(min, min);
	glVertex3f(-Bw - Bb, Bh, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw - Bb, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt, Bl);
	//right
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh + Bt + Btt, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw, Bh + Bt + Btt, Bl);
	//top
	glTexCoord2f(min, min);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh + Bt + Btt, Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh + Bt + Btt, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt, -Bl);
	glEnd();
	//glDisable(GL_TEXTURE_2D);
	glPopMatrix();//5
}
void bk3()
{
	glPushMatrix(); //2
	glTranslatef(-1.0f, -2.0f + B3h, 2.0f);// move to lie on the left corner of the table
	glRotatef(ang3, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	/////////////bottom cover///
	// bottom
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh, Bl);
	//Top
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh + Bt, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, Bl);
	//front
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, Bl);
	//back
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, -Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	//right
	glTexCoord2f(min, min);
	glVertex3f(Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	//left
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw, Bh + Bt, -Bl);

	glEnd();
	glPopMatrix();//2 

	///////////////top cover////////
	glPushMatrix(); //3
	glTranslatef(-1.0f, -2.0f + B3h + Btt3, 2.0f);// move up to lie above bottom cover
	glRotatef(ang3, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	// bottom
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh, Bl);
	//front
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, Bl);
	//back
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, -Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	//right
	glTexCoord2f(min, min);
	glVertex3f(Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	//left
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw, Bh + Bt, -Bl);

	glEnd();
	glPopMatrix();  //3
	////////////////////binding//////
	glPushMatrix();//5
	glTranslatef(-1.0f, -2.0f + B3h, 2.0f);
	glRotatef(ang3, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);

	//front
	glTexCoord2f(min, min);
	glVertex3f(-Bw - Bb, Bh, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh + Bt + Btt3, Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt3, Bl);
	//back
	glTexCoord2f(min, min);
	glVertex3f(-Bw - Bb, Bh, -Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh + Bt + Btt3, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt3, -Bl);
	//left
	glTexCoord2f(min, min);
	glVertex3f(-Bw - Bb, Bh, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw - Bb, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt3, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt3, Bl);
	//right
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh + Bt + Btt3, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw, Bh + Bt + Btt3, Bl);
	//top
	glTexCoord2f(min, min);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt3, Bl);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh + Bt + Btt3, Bl);
	glTexCoord2f(max, max);
	glVertex3f(-Bw, Bh + Bt + Btt3, -Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw - Bb, Bh + Bt + Btt3, -Bl);
	glEnd();
	//glDisable(GL_TEXTURE_2D);
	glPopMatrix();//5

}
void pgs()
{
	/////////pages of book 1
	glPushMatrix(); //4
	glTranslatef(-1.0f, -2.0f + Bt, 2.0f);// move to lie between covers
	glRotatef(ang1, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	//front
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Btt, Bl - 0.03f);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl - 0.03f);
	glTexCoord2f(max, max);
	glVertex3f(Bw - 0.03f, Bh, Bl - 0.03f);
	glTexCoord2f(min, max);
	glVertex3f(Bw - 0.03f, Bh + Btt, Bl - 0.03f);
	//back
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Btt, -Bl + 0.03f);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl + 0.03f);
	glTexCoord2f(max, max);
	glVertex3f(Bw - 0.03f, Bh, -Bl + 0.03f);
	glTexCoord2f(min, max);
	glVertex3f(Bw - 0.03f, Bh + Btt, -Bl + 0.03f);
	//right
	glTexCoord2f(min, min);
	glVertex3f(Bw - 0.03f, Bh + Btt, Bl - 0.03f);
	glTexCoord2f(max, min);
	glVertex3f(Bw - 0.03f, Bh, Bl - 0.03f);
	glTexCoord2f(max, max);
	glVertex3f(Bw - 0.03f, Bh, -Bl + 0.03f);
	glTexCoord2f(min, max);
	glVertex3f(Bw - 0.03f, Bh + Btt, -Bl + 0.03f);

	glEnd();
	glPopMatrix();  //4

	//////////////////pages of book 2///////////////
	glPushMatrix(); //8
	glTranslatef(-1.0f, -2.0f + B2h + Bt, 2.0f);// move to lie between covers
	glRotatef(ang2, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	//front
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Btt, Bl - 0.03f);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl - 0.03f);
	glTexCoord2f(max, max);
	glVertex3f(Bw - 0.03f, Bh, Bl - 0.03f);
	glTexCoord2f(min, max);
	glVertex3f(Bw - 0.03f, Bh + Btt, Bl - 0.03f);
	//back
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Btt, -Bl + 0.03f);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl + 0.03f);
	glTexCoord2f(max, max);
	glVertex3f(Bw - 0.03f, Bh, -Bl + 0.03f);
	glTexCoord2f(min, max);
	glVertex3f(Bw - 0.03f, Bh + Btt, -Bl + 0.03f);
	//right
	glTexCoord2f(min, min);
	glVertex3f(Bw - 0.03f, Bh + Btt, Bl - 0.03f);
	glTexCoord2f(max, min);
	glVertex3f(Bw - 0.03f, Bh, Bl - 0.03f);
	glTexCoord2f(max, max);
	glVertex3f(Bw - 0.03f, Bh, -Bl + 0.03f);
	glTexCoord2f(min, max);
	glVertex3f(Bw - 0.03f, Bh + Btt, -Bl + 0.03f);

	glEnd();
	glPopMatrix();  //8

	///////////////////////////////
	///////////pages of book 3
	glPushMatrix(); //12
	glTranslatef(-1.0f, -2.0f + B3h + Bt, 2.0f);// move to lie between covers
	glRotatef(ang3, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	//front
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Btt3, Bl - 0.03f);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, Bl - 0.03f);
	glTexCoord2f(max, max);
	glVertex3f(Bw - 0.03f, Bh, Bl - 0.03f);
	glTexCoord2f(min, max);
	glVertex3f(Bw - 0.03f, Bh + Btt3, Bl - 0.03f);
	//back
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Btt3, -Bl + 0.03f);
	glTexCoord2f(max, min);
	glVertex3f(-Bw, Bh, -Bl + 0.03f);
	glTexCoord2f(max, max);
	glVertex3f(Bw - 0.03f, Bh, -Bl + 0.03f);
	glTexCoord2f(min, max);
	glVertex3f(Bw - 0.03f, Bh + Btt3, -Bl + 0.03f);
	//right
	glTexCoord2f(min, min);
	glVertex3f(Bw - 0.03f, Bh + Btt3, Bl - 0.03f);
	glTexCoord2f(max, min);
	glVertex3f(Bw - 0.03f, Bh, Bl - 0.03f);
	glTexCoord2f(max, max);
	glVertex3f(Bw - 0.03f, Bh, -Bl + 0.03f);
	glTexCoord2f(min, max);
	glVertex3f(Bw - 0.03f, Bh + Btt3, -Bl + 0.03f);

	glEnd();
	glPopMatrix();  //12
}

static void FloorShadowObj(void)

{
	drwatableTop();
	Firstleg();
	secondleg();
	thirdleg();
	fourthleg();
	dglasscube();
	bk1();
	bk2();
	bk3();
	pgs();

}

static GLfloat floorVertices[4][3] = {
	{ -Rs, -2.0f, Rs },
	{ Rs, -2.0f, Rs },
	{ Rs, -2.0f, -Rs },
	{ -Rs, -2.0f, -Rs },
};

//////////////////////////

static void drawFloor(void)
{

	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glColor3f(0.90f, 0.90f, 0.90f);
	glVertex3fv(floorVertices[0]);
	glVertex3fv(floorVertices[1]);
	glVertex3fv(floorVertices[2]);
	glVertex3fv(floorVertices[3]);
	glEnd();

}

static GLfloat floorPlane[4];
static GLfloat floorShadow[4][4];
void drawSky()
{
	glEnable(GL_TEXTURE_2D);//enabling texture

	glBindTexture(GL_TEXTURE_2D, _textureId11);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_BLEND);//turns on alpha blending
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	
	glBegin(GL_QUADS);//normals pointing inwards
	glNormal3f(0, 1, 0);
	glColor4f(1, 1, 1, 0.6f);
	glTexCoord2f(0, 0);
	glVertex3f(-Rs, 8.0f, -Rs);
	glTexCoord2f(1, 0);
	glVertex3f(Rs, 8.0f, -Rs);
	glTexCoord2f(1, 1);
	glVertex3f(Rs, 8.0f, Rs);
	glTexCoord2f(0, 1);
	glVertex3f(-Rs, 8.0f, Rs);
	
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

}

void drawWall() //enclosing the walls of the room
{
	drawSky();
	glEnable(GL_TEXTURE_2D);//enabling texture

	glBindTexture(GL_TEXTURE_2D, _textureId10);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);//normals pointing outwards
	glNormal3f(0, 1, 0);
	
	
	////left
	glTexCoord2f(0, 0);
	glVertex3f(-Rs - wll, -2.0f, -Rs);
	glTexCoord2f(5, 0);
	glVertex3f(-Rs - wll, -2.0f, Rs);
	glTexCoord2f(5, 5);
	glVertex3f(-Rs - wll, 8.0f, Rs);
	glTexCoord2f(0, 5);
	glVertex3f(-Rs - wll, 8.0f, -Rs);
	////right
	glTexCoord2f(0, 0);
	glVertex3f(Rs + wll, -2.0f, Rs);
	glTexCoord2f(5, 0);
	glVertex3f(Rs + wll, -2.0f, -Rs);
	glTexCoord2f(5, 5);
	glVertex3f(Rs + wll, 8.0f, -Rs);
	glTexCoord2f(0, 5);
	glVertex3f(Rs + wll, 8.0f, Rs);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void drawWallM() //enclosing the walls of the room
{
	glEnable(GL_TEXTURE_2D);//enabling texture

	glBindTexture(GL_TEXTURE_2D, _textureId10);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);//normals pointing outwards
	glNormal3f(0, 1, 0);
	////left
	glTexCoord2f(0, 0);
	glVertex3f(-Rs - wll, -2.0f, -Rs);
	glTexCoord2f(5, 0);
	glVertex3f(-Rs - wll, -2.0f, Rs);
	glTexCoord2f(5, 5);
	glVertex3f(-Rs - wll, 8.0f, Rs);
	glTexCoord2f(0, 5);
	glVertex3f(-Rs - wll, 8.0f, -Rs);
	////right
	glTexCoord2f(0, 0);
	glVertex3f(Rs + wll, -2.0f, Rs);
	glTexCoord2f(5, 0);
	glVertex3f(Rs + wll, -2.0f, -Rs);
	glTexCoord2f(5, 5);
	glVertex3f(Rs + wll, 8.0f, -Rs);
	glTexCoord2f(0, 5);
	glVertex3f(Rs + wll, 8.0f, Rs);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}


void glasscube(){
	glEnable(GL_TEXTURE_2D);//enabling texture

	glBindTexture(GL_TEXTURE_2D, _textureId1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_BLEND);//turns on alpha blending
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
	dglasscube();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);

}

void drawtable(){
	glEnable(GL_TEXTURE_2D);//enabling texture

	glBindTexture(GL_TEXTURE_2D, _textureId3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	drwatableTop();
	Firstleg();
	secondleg();
	thirdleg();
	fourthleg();

	glDisable(GL_TEXTURE_2D);
	
}

void book1(){
	glEnable(GL_TEXTURE_2D);//enabling texture

	glBindTexture(GL_TEXTURE_2D, _textureId9);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	bk1();
	
	glDisable(GL_TEXTURE_2D);
	
}
void book1top()
{
	glEnable(GL_TEXTURE_2D);//enabling texture

	glBindTexture(GL_TEXTURE_2D, _textureId8);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);


	glPushMatrix(); //3
	glTranslatef(-1.0f, -2.0f + Btt, 2.0f);// move up to lie above bottom cover
	glRotatef(ang1, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);

	//Top
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw, Bh + Bt, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	glTexCoord2f(max, min);
	glVertex3f(Bw, Bh + Bt, Bl);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void book2()
{
	glEnable(GL_TEXTURE_2D);//enabling texture

	glBindTexture(GL_TEXTURE_2D, _textureId5);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	bk2();

	glDisable(GL_TEXTURE_2D);

}
void book2top()

{
	glEnable(GL_TEXTURE_2D);//enabling texture

	glBindTexture(GL_TEXTURE_2D, _textureId4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);


	glPushMatrix(); //3
	glTranslatef(-1.0f, -2.0f + B2h + Btt, 2.0f);// move up to lie above bottom cover
	glRotatef(ang2, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);

	//Top
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw, Bh + Bt, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	glTexCoord2f(max, min);
	glVertex3f(Bw, Bh + Bt, Bl);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void book3()

{
	glEnable(GL_TEXTURE_2D);//enabling texture

	glBindTexture(GL_TEXTURE_2D, _textureId7);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	bk3();

	glDisable(GL_TEXTURE_2D);
	
}
void book3top()


{
	glEnable(GL_TEXTURE_2D);//enabling texture

	glBindTexture(GL_TEXTURE_2D, _textureId6);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);


	glPushMatrix(); //3
	glTranslatef(-1.0f, -2.0f + B3h + Btt3, 2.0f);// move up to lie above bottom cover
	glRotatef(ang3, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);

	//Top
	glTexCoord2f(min, min);
	glVertex3f(-Bw, Bh + Bt, Bl);
	glTexCoord2f(min, max);
	glVertex3f(-Bw, Bh + Bt, -Bl);
	glTexCoord2f(max, max);
	glVertex3f(Bw, Bh + Bt, -Bl);
	glTexCoord2f(max, min);
	glVertex3f(Bw, Bh + Bt, Bl);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void pages(){//textures must be added
	glEnable(GL_TEXTURE_2D);//enabling texture

	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    pgs();
	glDisable(GL_TEXTURE_2D);

}

//////////////////////////////////////////////////////////////////////

