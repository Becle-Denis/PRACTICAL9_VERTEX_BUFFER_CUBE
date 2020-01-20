#include <Game.h>

static bool flip;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube VBO")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

typedef struct
{
	float coordinate[3];
	float color[3];
} Vertex;

Vertex vertex[6];
GLubyte triangles[6];

/* Variable to hold the VBO identifier */
GLuint vbo[1];
GLuint index;

void Game::initialize()
{
	isRunning = true;
	
	glewInit();

	//Cubes Points 
	// FACE 
	// A : -1, 1 -5
	// B : 1, 1, -5 
	// C : 1, -1, -5
	// D : -1, -1, -5
	//BACK 
	// E : -1, 1, -7
	// F : 1, 1, -7
	// G : 1, -1, -7
	// H : -1, -1, -7

	//Point A 
	//vertex[A].coordinate[0] = -1.0f;
	//vertex[A].coordinate[1] = 1.0f;
	//vertex[A].coordinate[2] = -5.0f;

	//Point B 
	//vertex[B].coordinate[0] = 1.0f;
	//vertex[B].coordinate[1] = 1.0f;
	//vertex[B].coordinate[2] = -5.0f;

	//Point C 
	//vertex[C].coordinate[0] = 1.0f;
	//vertex[C].coordinate[1] = -1.0f;
	//vertex[C].coordinate[2] = -5.0f;

	//Point D 
	//vertex[D].coordinate[0] = -1.0f;
	//vertex[D].coordinate[1] = -1.0f;
	//vertex[D].coordinate[2] = -5.0f;

	//Point E 
	//vertex[E].coordinate[0] = -1.0f;
	//vertex[E].coordinate[1] = 1.0f;
	//vertex[E].coordinate[2] = -7.0f;

	//Point F 
	//vertex[F].coordinate[0] = 1.0f;
	//vertex[F].coordinate[1] = 1.0f;
	//vertex[F].coordinate[2] = -7.0f;

	//Point G 
	//vertex[G].coordinate[0] = 1.0f;
	//vertex[G].coordinate[1] = -1.0f;
	//vertex[G].coordinate[2] = -7.0f;

	//Point H 
	//vertex[H].coordinate[0] = -1.0f;
	//vertex[H].coordinate[1] = -1.0f;
	//vertex[H].coordinate[2] = -7.0f;


	/* Vertices counter-clockwise winding */

	//--------------------------T1 EFG---------------------------------------
	//Point E 
	vertex[0].coordinate[0] = -1.0f;
	vertex[0].coordinate[1] = 1.0f;
	vertex[0].coordinate[2] = -7.0f;

	//Point F 
	vertex[1].coordinate[0] = 1.0f;
	vertex[1].coordinate[1] = 1.0f;
	vertex[1].coordinate[2] = -7.0f;

	//Point G 
	vertex[2].coordinate[0] = 1.0f;
	vertex[2].coordinate[1] = -1.0f;
	vertex[2].coordinate[2] = -7.0f;

	//--------------------------T2 FGH---------------------------------------
	//Point F
	vertex[3].coordinate[0] = 1.0f;
	vertex[3].coordinate[1] = 1.0f;
	vertex[3].coordinate[2] = -7.0f;

	//Point G
	vertex[4].coordinate[0] = 1.0f;
	vertex[4].coordinate[1] = -1.0f;
	vertex[4].coordinate[2] = -7.0f;

	//Point H
	vertex[5].coordinate[0] = -1.0f;
	vertex[5].coordinate[1] = -1.0f;
	vertex[5].coordinate[2] = -7.0f;
	

	//--------------------------T3 CDG---------------------------------------
	//--------------------------T4 DGH---------------------------------------
	//--------------------------T5 DEH---------------------------------------
	//--------------------------T6 ADE---------------------------------------
	//--------------------------T7 BCG---------------------------------------
	//--------------------------T8 BFG---------------------------------------
	//--------------------------T9 ABE---------------------------------------
	//--------------------------T10 BEF--------------------------------------
	//--------------------------T11 ABC---------------------------------------
	//--------------------------T12 BCD---------------------------------------


	vertex[0].color[0] = 0.1f;
	vertex[0].color[1] = 1.0f;
	vertex[0].color[2] = 0.0f;

	vertex[1].color[0] = 0.2f;
	vertex[1].color[1] = 1.0f;
	vertex[1].color[2] = 0.0f;

	vertex[2].color[0] = 0.3f;
	vertex[2].color[1] = 1.0f;
	vertex[2].color[2] = 0.0f;

	vertex[3].color[0] = 0.4f;
	vertex[3].color[1] = 1.0f;
	vertex[3].color[2] = 0.0f;

	vertex[4].color[0] = 0.5f;
	vertex[4].color[1] = 1.0f;
	vertex[4].color[2] = 0.0f;

	vertex[5].color[0] = 0.6f;
	vertex[5].color[1] = 1.0f;
	vertex[5].color[2] = 0.0f;


	triangles[0] = 0;   triangles[1] = 1;   triangles[2] = 2;
	triangles[3] = 3;   triangles[4] = 4;   triangles[5] = 5;

	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);

	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Upload vertex data to GPU */
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 6, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * 6, triangles, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{

	}


	/*
	//Change vertex data
	vertex[0].coordinate[0] += -0.0001f;
	vertex[0].coordinate[1] += -0.0001f;
	vertex[0].coordinate[2] += -0.0001f;
	*/

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);

	/*	As the data positions will be updated by the this program on the
		CPU bind the updated data to the GPU for drawing	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 6, vertex, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glColorPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 12);

	/*	Draw Triangle from VBO	(set where to start from as VBO can contain 
		model compoents that are and are not to be drawn )	*/
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, (char*)NULL + 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;

	glDeleteBuffers(1, vbo);
}

