float angle = 0.0f; //actual vector represetnation of camera angle
float lx = 0.0f, lz = -1.0f; //camera direction vector
float cx = -1.0f, cy = 1.0f, z = 13.0f; //XZ position of camera

float _angle = 0.0f;
float _cameraAngle = -30.0f;

//for camera() rotation
void handleSpecialKeypress(
		int key, // key 2 be pressed
		int x,
		int y
) {
	float fraction = 0.8f;
	switch (key) {
		//addition of other keys for movement of camera>> might need for project
		case GLUT_KEY_LEFT://charachter A
			angle -= 0.1f;//shift angle by 0.1f in opposite angle then it looks like we are actually looking at positive
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT:
			angle += 0.1f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP:
			cx += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN:
			cx -= lx * fraction;
			z -= lz * fraction;
			break;
	}
}

void update(int value) {
	_angle += 1.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	glutPostRedisplay();//redraw scene
	glutTimerFunc(25, update, 0);
}
