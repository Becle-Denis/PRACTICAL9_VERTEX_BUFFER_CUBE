#include <Game.h>

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

Vertex vertex[12]; ////////////////////////////AAAAA
GLubyte triangles[12]; /////////////////////////AAAAA

/* Variable to hold the VBO identifier */
GLuint vbo[1];
GLuint index;

void Game::initialize()
{
	isRunning = true;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

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
	vertex[3].coordinate[0] = -1.0f; //!!!!
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
	//Point C 
	vertex[6].coordinate[0] = 1.0f;
	vertex[6].coordinate[1] = -1.0f;
	vertex[6].coordinate[2] = -5.0f;

	//Point D 
	vertex[7].coordinate[0] = -1.0f;
	vertex[7].coordinate[1] = -1.0f;
	vertex[7].coordinate[2] = -5.0f;

	//Point G
	vertex[8].coordinate[0] = 1.0f;
	vertex[8].coordinate[1] = -1.0f;
	vertex[8].coordinate[2] = -7.0f;

	//--------------------------T4 DGH---------------------------------------
	//Point D 
	vertex[9].coordinate[0] = -1.0f;
	vertex[9].coordinate[1] = -1.0f;
	vertex[9].coordinate[2] = -5.0f;

	//Point G
	vertex[10].coordinate[0] = 1.0f;
	vertex[10].coordinate[1] = -1.0f;
	vertex[10].coordinate[2] = -7.0f;

	//Point H
	vertex[11].coordinate[0] = -1.0f;
	vertex[11].coordinate[1] = -1.0f;
	vertex[11].coordinate[2] = -7.0f;


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

	vertex[6].color[0] = 0.4f;
	vertex[6].color[1] = 1.0f;
	vertex[6].color[2] = 0.0f;

	vertex[7].color[0] = 0.5f;
	vertex[7].color[1] = 1.0f;
	vertex[7].color[2] = 0.0f;

	vertex[8].color[0] = 0.6f;
	vertex[8].color[1] = 1.0f;
	vertex[8].color[2] = 0.0f;

	vertex[9].color[0] = 0.4f;
	vertex[9].color[1] = 1.0f;
	vertex[9].color[2] = 0.0f;

	vertex[10].color[0] = 0.5f;
	vertex[10].color[1] = 1.0f;
	vertex[10].color[2] = 0.0f;

	vertex[11].color[0] = 0.6f;
	vertex[11].color[1] = 1.0f;
	vertex[11].color[2] = 0.0f;


	triangles[0] = 0;   triangles[1] = 1;   triangles[2] = 2;
	triangles[3] = 3;   triangles[4] = 4;   triangles[5] = 5;
	triangles[6] = 6;   triangles[7] = 7;   triangles[8] = 8;
	triangles[9] = 9;   triangles[10] = 10;   triangles[11] = 11;


	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);

	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Upload vertex data to GPU */
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * VERTEX_NUMBER, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * VERTEX_NUMBER, triangles, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	//Allowed movement
	if (movementCLock.getElapsedTime() > sf::milliseconds(30))
	{
		movementCLock.restart();

		//center calculation 
		float sumX = 0;
		float sumY = 0;
		float sumZ = 0;
		for (int i = 0; i < VERTEX_NUMBER; i ++)
		{
			sumX += vertex[i].coordinate[0];
			sumY += vertex[i].coordinate[1];
			sumZ += vertex[i].coordinate[2];
		}
		db::Vector3 center(sumX / VERTEX_NUMBER, sumY / VERTEX_NUMBER, sumZ / VERTEX_NUMBER);

		//------------ROTATING--------------------------

		// rotation X 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				//adapting to vector
				db::Vector3 v(vertex[i].coordinate[0], vertex[i].coordinate[1], vertex[i].coordinate[2]);

				//rotating
				v = v - center;
				v = v * db::Matrix3::rotationX(1);
				v = v + center;

				//reassigning value 
				vertex[i].coordinate[0] = v.x;
				vertex[i].coordinate[1] = v.y;
				vertex[i].coordinate[2] = v.z;
			}
		}


		// rotation Y
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				//adapting to vector
				db::Vector3 v(vertex[i].coordinate[0], vertex[i].coordinate[1],vertex[i].coordinate[2]);

				//rotating
				v = v - center;
				v = v * db::Matrix3::rotationY(1);
				v = v + center;

				//reassigning value 
				vertex[i].coordinate[0] = v.x;
				vertex[i].coordinate[1] = v.y;
				vertex[i].coordinate[2] = v.z;
			}
		}

		// rotation Z 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				//adapting to vector
				db::Vector3 v(vertex[i].coordinate[0], vertex[i].coordinate[1], vertex[i].coordinate[2]);

				//rotating
				v = v - center;
				v = v * db::Matrix3::rotationZ(1);
				v = v + center;

				//reassigning value 
				vertex[i].coordinate[0] = v.x;
				vertex[i].coordinate[1] = v.y;
				vertex[i].coordinate[2] = v.z;
			}
		}

		//------------TRANSLATING------------------------

		// Translating right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				//adapting to vector
				db::Vector3 v(vertex[i].coordinate[0], vertex[i].coordinate[1], 1);

				//translating
				v = v * db::Matrix3::translate(1, 0);

				//reassigning value
				vertex[i].coordinate[0] = v.x;
				vertex[i].coordinate[1] = v.y;
			}
		}

		// Translating left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				//adapting to vector
				db::Vector3 v(vertex[i].coordinate[0], vertex[i].coordinate[1], 1);

				//translating
				v = v * db::Matrix3::translate(-1, 0);

				//reassigning value
				vertex[i].coordinate[0] = v.x;
				vertex[i].coordinate[1] = v.y;
			}
		}

		// Translating up
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				//adapting to vector
				db::Vector3 v(vertex[i].coordinate[0], vertex[i].coordinate[1], 1);

				//translating
				v = v * db::Matrix3::translate(0, 1);

				//reassigning value
				vertex[i].coordinate[0] = v.x;
				vertex[i].coordinate[1] = v.y;
			}
		}

		// Translating down
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				//adapting to vector
				db::Vector3 v(vertex[i].coordinate[0], vertex[i].coordinate[1], 1);

				//translating
				v = v * db::Matrix3::translate(0, -1);

				//reassigning value
				vertex[i].coordinate[0] = v.x;
				vertex[i].coordinate[1] = v.y;
			}
		}

		// Scalling up
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				//adapting to vector
				db::Vector3 v(vertex[i].coordinate[0], vertex[i].coordinate[1], vertex[i].coordinate[2]);

				//scalling
				v = v - center;
				v = v * db::Matrix3::scale3D(101);
				v = v + center;

				//reassigning value
				vertex[i].coordinate[0] = v.x;
				vertex[i].coordinate[1] = v.y;
				vertex[i].coordinate[2] = v.z;
			}
		}

		// Scalling Down
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			for (int i = 0; i < VERTEX_NUMBER; i++)
			{
				//adapting to vector
				db::Vector3 v(vertex[i].coordinate[0], vertex[i].coordinate[1], vertex[i].coordinate[2]);

				//scalling
				v = v - center;
				v = v * db::Matrix3::scale3D(99);
				v = v + center;

				//reassigning value
				vertex[i].coordinate[0] = v.x;
				vertex[i].coordinate[1] = v.y;
				vertex[i].coordinate[2] = v.z;
			}
		}

	}

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
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * VERTEX_NUMBER, vertex, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glColorPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 12);

	/*	Draw Triangle from VBO	(set where to start from as VBO can contain 
		model compoents that are and are not to be drawn )	*/
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 0);
	glDrawElements(GL_TRIANGLES, VERTEX_NUMBER, GL_UNSIGNED_BYTE, (char*)NULL + 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;

	glDeleteBuffers(1, vbo);
}

