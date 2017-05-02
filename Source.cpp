#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "body.h"
#include "Camera.h"
#include "Shadow.h"
#include "Light.h"
#include "Mirror.h"

#include <math.h>      
   
#ifndef M_PI
#define M_PI 3.14159265
#endif

enum {
	M_NONE, M_MOTION, M_LIGHT, M_SHADOWS, M_REFLECTION, M_FloorShadowObj,
	M_STENCIL_REFLECTION, M_STENCIL_SHADOW, M_OFFSET_SHADOW,
	M_POSITIONAL, M_DIRECTIONAL, M_PERFORMANCE
};

using namespace std;

void handleResize(int w, int h){

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);


	glLoadIdentity();
	gluPerspective(
		45.0,//camera angle
		(double)w / (double)h,//the width to height ratio
		1.0, //near z clipping coordinate
		200.0);// the far z clipping coordinate


}

void drawAllObjects(){

	drawtable();//draw table
	book1();
	book1top();
	book2();
	book2top();
	book3();
	book3top();
	pages();
	glasscube();
	drawWallM();

}


void drawScene(){

	
	//clear informatoin from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //switch the drawing perspective
	glLoadIdentity();//Reset the drawing perspective

	//Camera (View port)
	gluLookAt( cx, cy, z, cx + lx, 1.0f, z + lz, 0.0f, 1.0f, 0.0f);
	drawMirrors();
	drawWall();
glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	
	drawAllObjects();

	
	glCullFace(GL_BACK);// draws back afterwards
	
	drawAllObjects();

	glDisable(GL_CULL_FACE);

	glFlush();

	int start, end;

	if (reportSpeed) {
		start = glutGet(GLUT_ELAPSED_TIME);
	}

	/* Reposition the light source. */
	lightPosition[0] = 20 * cos(lightAngle);
	lightPosition[1] = 20 * sin(lightAngle);
	lightPosition[2] =  lightHeight;
	lightPosition[3] = 0.0;

	shadowMatrix(floorShadow, floorPlane, lightPosition);

	glPushMatrix();
	/* Perform scene rotations based on user mouse input. */
	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(ang, 0.0, 1.0, 0.0);

	/* Tell GL new light source position. */
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);


	
	if (renderShadow) {
		if (stencilShadow) {
			/* Draw the floor with stencil value 3.  This helps us only
			draw the shadow once per floor pixel (and only on the
			floor pixels). */
			glEnable(GL_STENCIL_TEST);
			glStencilFunc(GL_ALWAYS, 3, 0xffffffff);
			glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
		}
	}
	

	/* Draw "top" of floor.  Use blending to blend in reflection. */
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.7f, 0.0f, 0.0f, 0.3f);

	drawFloor();
	glDisable(GL_BLEND);

	if (FloorShadow) {

		FloorShadowObj();
	}

	if (FloorShadow) {

		/* Render the projected shadow. */

		if (stencilShadow) {

			/* Now, only render where stencil is set above 2 (ie, 3 where
			the top floor is).  Update stencil with 2 where the shadow
			gets drawn so we don't redraw (and accidently reblend) the
			shadow). */
			glStencilFunc(GL_LESS, 2, 0xffffffff);  /* draw if ==1 */
			glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
		}

		/* To eliminate depth buffer artifacts, we use polygon offset
		to raise the depth of the projected shadow slightly so
		that it does not depth buffer alias with the floor. */
		if (offsetShadow) {
			switch (polygonOffsetVersion) {
			case EXTENSION:
			#ifdef GL_EXT_polygon_offset
				glEnable(GL_POLYGON_OFFSET_EXT);
				break;
		#endif
			#ifdef GL_VERSION_1_1
			case ONE_DOT_ONE:
				glEnable(GL_POLYGON_OFFSET_FILL);
				break;
		#endif
			case MISSING:
				break;
			}
		}

		/* Render 50% black shadow color on top of whatever the
		floor appareance is. */
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDisable(GL_LIGHTING);  /* Force the 50% black. */
		glColor4f(0.0, 0.0, 0.0, 0.5);

		glPushMatrix();
		/* Project the shadow. */
		glMultMatrixf((GLfloat *)floorShadow);
		FloorShadowObj();
		glPopMatrix();

		glDisable(GL_BLEND);
		glEnable(GL_LIGHTING);

		if (offsetShadow) {
			switch (polygonOffsetVersion) {
			#ifdef GL_EXT_polygon_offset
			case EXTENSION:
				glDisable(GL_POLYGON_OFFSET_EXT);
				break;
		#endif
			#ifdef GL_VERSION_1_1
			case ONE_DOT_ONE:
				glDisable(GL_POLYGON_OFFSET_FILL);
				break;
		#endif
			case MISSING:
				break;
			}
		}
		if (stencilShadow) {
			glDisable(GL_STENCIL_TEST);
		}
	}

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 0.0);
	
	/* Draw a yellow ball at the light source. */
	glTranslatef(lightPosition[0], lightPosition[1], lightPosition[2]);
	glutSolidSphere(3.0, 75, 75);
	
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPopMatrix();
	

	if (reportSpeed) {
		glFinish();
		end = glutGet(GLUT_ELAPSED_TIME);
		printf("Speed %.3g frames/sec (%d ms)\n", 100.0 / (end - start), end - start);
	}

	glutSwapBuffers();//sends the 3D scene to screen
}

static void controlLights(int value)
{
	switch (value) {
	case M_NONE:
		return;
	case M_MOTION:
		animation = 1 - animation;
		if (animation) {
			glutIdleFunc(idle);
		}
		else {
			glutIdleFunc(NULL);
		}
		break;
	case M_LIGHT:
		lightSwitch = !lightSwitch;
		if (lightSwitch) {
			glEnable(GL_LIGHT0);
		}
		else {
			glDisable(GL_LIGHT0);
		}
		break;

	case M_SHADOWS:
		renderShadow = 1 - renderShadow;
		break;
	
	case M_FloorShadowObj:
		FloorShadow = 1 - FloorShadow;
		break;
	
	case M_STENCIL_SHADOW:
		stencilShadow = 1 - stencilShadow;
		break;
	case M_OFFSET_SHADOW:
		offsetShadow = 1 - offsetShadow;
		break;
	case M_POSITIONAL:
		directionalLight = 0;
		break;
	case M_DIRECTIONAL:
		directionalLight = 1;
		break;
	}
	glutPostRedisplay();
}

static void visible(int vis)
{
	if (vis == GLUT_VISIBLE) {
		if (animation)
			glutIdleFunc(idle);
	}
	else {
		if (!animation)
			glutIdleFunc(NULL);
	}
}

void handleKeypress(unsigned char key,int x, int y){ 
	float fraction = 0.1f; //amount to be changed per press action
	switch (key)
	{
	case 27: //escape key
		exit(0); //exit the process
	case 'q':
		cx = -15.0f;
		cy = 8.0f;
		z = 15.0f;
		lx = +15.0f;
		lz = -15.0f;
		drawScene();
		break;
	case 'w':
		cx = 15.0f;
		cy = 0.0f;
		z = 15.0f;
		lx = -15.0f;
		lz = -15.0f;
		drawScene();
		break;
	case 'e':
		cx = 15.0f;
		cy = 8.0f;
		z = -15.0f;
		lx = -15.0f;
		lz = 15.0f;
		drawScene();
		break;
	case 'r':
		cx = -1.0f;
		cy = 1.0f;
		z = 13.0f;
		lx = 0.0f;
		lz = -1.0f;
		drawScene();
		break;
	default:
		cx = -1.0f;
		cy = 1.0f;
		z = 13.0f;
		lx = 0.0f;
		lz = -1.0f;
		drawScene();
		break;
	}

}

static int supportsOneDotOne(void)
{
	const char *version;
	int major, minor;

	version = (char *)glGetString(GL_VERSION);
	if (sscanf_s(version, "%d.%d", &major, &minor) == 2)
		return major >= 1 && minor >= 1;
	return 0;           
}

int main(int argc, char* argv[]){


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL | GLUT_MULTISAMPLE);
	glutInitWindowSize(600, 600);//size of window
	glutCreateWindow("GROUP 5-SCENE 3");
	initRender();//initialize rendering 

	glutDisplayFunc(drawScene);


	glutVisibilityFunc(visible);

	glutKeyboardFunc(handleKeypress);

	glutCreateMenu(controlLights);
	glutAddMenuEntry("Toggle motion", M_MOTION);
	glutAddMenuEntry("-----------------------", M_NONE);
	glutAddMenuEntry("Toggle light", M_LIGHT);

	glutAddMenuEntry("Toggle shadows", M_SHADOWS);

	glutAddMenuEntry("Toggle objects", M_FloorShadowObj);
	glutAddMenuEntry("-----------------------", M_NONE);

	glutAddMenuEntry("Toggle shadow stenciling", M_STENCIL_SHADOW);
	glutAddMenuEntry("Toggle shadow offset", M_OFFSET_SHADOW);
	glutAddMenuEntry("----------------------", M_NONE);

	glutAttachMenu(GLUT_RIGHT_BUTTON);


#ifdef GL_VERSION_1_1
	if (supportsOneDotOne() && !forceExtension) {
		polygonOffsetVersion = ONE_DOT_ONE;
		glPolygonOffset(-2.0, -1.0);
	}
	else
#endif

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	glLineWidth(3.0);

	glMatrixMode(GL_PROJECTION);
	gluPerspective( /* field of view in degree */ 40.0f,
		/* aspect ratio */ 1.0f,
		/* Z near */ 20.0f, /* Z far */ 100.0f);
	glMatrixMode(GL_MODELVIEW);


	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.1f);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05f);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

findPlane(floorPlane, floorVertices[1], floorVertices[2], floorVertices[3]);

	glutSpecialFunc(handleSpecialKeypress);// camera rotation
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);

	cout << "press Q, W, E to change positions of static/directional camera " ;
	cout << "\n ";
	cout << "press R to come back to default dynamic camera";
	cout << "\n";
	cout << "use arrow keys to move default dynamic camera";
	cout << "\n";
	cout << "right click to get the menu ";
	glutMainLoop(); 
	return 0; 

}