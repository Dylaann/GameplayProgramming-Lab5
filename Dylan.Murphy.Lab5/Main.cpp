
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#include "Game.h"

int main(void)
{
	Game& game = Game();
	game.run();
}