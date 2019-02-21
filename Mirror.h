void drawObjectsforMirror() {
	drawTable();
	book1();
	book1top();
	book2();
	book2top();
	book3();
	book3top();
	pages();
	glasscube();
	drawWallM();
	drawFloor();
}

void drawMirrors() {
	GLint buffers = GL_NONE;	//get current color buffer from being drawn
	glGetIntegerv(GL_DRAW_BUFFER, &buffers);	// set the clear value

	glClearStencil(0x00);	// clear the stencil buffer
	glEnable(GL_STENCIL_TEST);
	glColorMask(0, 0, 0, 0); //Disable drawing colors to the screen
	// always pass the stencil test

	glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);	// disable drawing to the color buffer	
	glStencilFunc(GL_ALWAYS, 1, 0xffffffff);	// set the operation to modify the stencil buffer

	//this would be the stencil mask-->
	glDisable(GL_DEPTH_TEST);
	glBegin(GL_QUADS);
	//back wall
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-Rs, -2.0f, -Rs);
	glVertex3f(Rs, -2.0f, -Rs);
	glVertex3f(Rs, 8.0f, -Rs);
	glVertex3f(-Rs, 8.0f, -Rs);
	glEnd();

	//added on june 5th
	glBegin(GL_QUADS);
	////Frontwall
	glVertex3f(-Rs, 8.0f, Rs);
	glVertex3f(Rs, 8.0f, Rs);
	glVertex3f(Rs, -2.0f, Rs);
	glVertex3f(-Rs, -2.0f, Rs);
	glEnd();
	////////////////////////////////////////////////

	// reenable drawing to color buffer
	glDrawBuffer((GLenum)buffers);

	glColorMask(1, 1, 1, 1); //Enable drawing colors to the screen
	glStencilFunc(GL_EQUAL, 1, 0xffffffff); 		// draw only where the stencil buffer == 1

	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);	// make stencil buffer read only
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// clear the color and depth buffers

	glEnable(GL_DEPTH_TEST);
	glPushMatrix();	// draw the mirror image

	//this method works however when we move out of the room we see reflections to the back of it aswell
	for (float k = 2.0f; k < 20; k = k + 2) {
		// invert image about xy plane
		glScalef(1.0f, 1.0f, -1.0f);
		glTranslatef(0.0f, 0.0f, k*Rs);
		drawObjectsforMirror();
	}

	glPopMatrix();

	glDisable(GL_STENCIL_TEST);	// disable the stencil buffer
	glDrawBuffer(GL_NONE);	// disable drawing to the color buffer

	glDrawBuffer((GLenum)buffers);
}