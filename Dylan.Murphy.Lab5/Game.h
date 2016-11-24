#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h> 
#include <gl/GLU.h> 
#include "Matrix3.h"
#include "Vector3.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	Vector3new v1 = Vector3new(2.0, 3, -10);
	Vector3new v2 = Vector3new(1.0, -3, -10);
	Vector3new v3 = Vector3new(1.0, -3, -100);

	Matrix3new rotationM = Matrix3new(0, 0, 1, 0, 1, 0, -1, 0, 0);
};