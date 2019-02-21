/* Variable controlling various rendering modes. */
static int stencilShadow = 1, offsetShadow = 1;
static int renderShadow = 1, FloorShadow = 1;

static int reportSpeed = 0;

static int forceExtension = 0;

enum {
	MISSING,
	EXTENSION,
	ONE_DOT_ONE
};
int polygonOffsetVersion;

enum {
	X,
	Y,
	Z,
	W
};
enum {
	A,
	B,
	C,
	D
};

/* Create a matrix that will project the desired shadow. */
void shadowMatrix(GLfloat shadowMat[4][4], GLfloat groundplane[4], GLfloat lightpos[4]) {
	GLfloat dot;

	/* Find dot product between light position vector and ground plane normal. */
	dot = groundplane[X] * lightpos[X] +
		  groundplane[Y] * lightpos[Y] +
		  groundplane[Z] * lightpos[Z] +
		  groundplane[W] * lightpos[W];

	shadowMat[0][0] = dot - lightpos[X] * groundplane[X];
	shadowMat[1][0] = 0.f - lightpos[X] * groundplane[Y];
	shadowMat[2][0] = 0.f - lightpos[X] * groundplane[Z];
	shadowMat[3][0] = 0.f - lightpos[X] * groundplane[W];

	shadowMat[X][1] = 0.f - lightpos[Y] * groundplane[X];
	shadowMat[1][1] = dot - lightpos[Y] * groundplane[Y];
	shadowMat[2][1] = 0.f - lightpos[Y] * groundplane[Z];
	shadowMat[3][1] = 0.f - lightpos[Y] * groundplane[W];

	shadowMat[X][2] = 0.f - lightpos[Z] * groundplane[X];
	shadowMat[1][2] = 0.f - lightpos[Z] * groundplane[Y];
	shadowMat[2][2] = dot - lightpos[Z] * groundplane[Z];
	shadowMat[3][2] = 0.f - lightpos[Z] * groundplane[W];

	shadowMat[X][3] = 0.f - lightpos[W] * groundplane[X];
	shadowMat[1][3] = 0.f - lightpos[W] * groundplane[Y];
	shadowMat[2][3] = 0.f - lightpos[W] * groundplane[Z];
	shadowMat[3][3] = dot - lightpos[W] * groundplane[W];

}

/* Find the plane equation given 3 points. */
void findPlane(GLfloat plane[4], GLfloat v0[3], GLfloat v1[3], GLfloat v2[3]) {
	GLfloat vec0[3], vec1[3];

	/* Need 2 vectors to find cross product. */
	vec0[X] = v1[X] - v0[X];
	vec0[Y] = v1[Y] - v0[Y];
	vec0[Z] = v1[Z] - v0[Z];

	vec1[X] = v2[X] - v0[X];
	vec1[Y] = v2[Y] - v0[Y];
	vec1[Z] = v2[Z] - v0[Z];

	/* find cross product to get A, B, and C of plane equation */
	plane[A] = vec0[Y] * vec1[Z] - vec0[Z] * vec1[Y];
	plane[B] = -(vec0[X] * vec1[Z] - vec0[Z] * vec1[X]);
	plane[C] = vec0[X] * vec1[Y] - vec0[Y] * vec1[X];

	plane[D] = -(plane[A] * v0[X] + plane[B] * v0[Y] + plane[C] * v0[Z]);
}

/* Enumerants for refering to display lists. */
typedef enum {
	RESERVED,
	BODY_SIDE,
	BODY_EDGE,
	BODY_WHOLE,
	ARM_SIDE,
	ARM_EDGE,
	ARM_WHOLE,
	LEG_SIDE,
	LEG_EDGE,
	LEG_WHOLE,
	EYE_SIDE,
	EYE_EDGE,
	EYE_WHOLE
}

displayLists;
