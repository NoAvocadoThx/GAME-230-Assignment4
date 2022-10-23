//*****************************************************************
// GAME 230 assignment 4
// Main.cpp
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Game.h"

using namespace sf;
using namespace gm;



//*****************************************************************
int main()
{

	RenderWindow Window(VideoMode(1000, 1000), "Game 230 Assignment 3");
	Game g;
	Window.setFramerateLimit(60);
	Clock deltaClock;


	while (Window.isOpen())
	{
		Time dt = deltaClock.restart();

		// Our game object handles the game loop programming pattern
		g.handleInput(Window);

		g.update(Window, dt.asSeconds());

		g.render(Window);

		
	}

	return 0;
}

