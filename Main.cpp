//*****************************************************************
// GAME 230 assignment 4
// Main.cpp
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

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
		Time dt = deltaClock.getElapsedTime();
		if (!g.isRepeating) {
			dt = deltaClock.restart();
		}

		// Our game object handles the game loop programming pattern
		g.handleInput(Window);

		g.update(Window, dt.asSeconds());

		g.render(Window);

		
	}
	
	return 0;
}

