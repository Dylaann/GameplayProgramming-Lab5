#include "Game.h"

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;
	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	cout << "Update up" << endl;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		v1 = rotationM * v1;
		v2 = rotationM * v2 ;
		v3 = rotationM * v3 ;
	}
}

void Game::draw()
{
	cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLE_FAN);
	{ 
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(v1.x, v1.y, v1.z);

		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(v2.x, v2.y, v2.z);

		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(v3.x, v3.y, v3.z);
	} 
	glEnd();

	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

