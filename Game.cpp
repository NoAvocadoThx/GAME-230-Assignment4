// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"


// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() {
	//test.setPosition(Vector2f(400, 300));
	//test.setSize(50);
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput(sf::RenderWindow& window) {
	// Check for events from the window
	// E.g., is the window being closed?
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		// query keyboard pressed events
		if (event.type == Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				if (Effect != nullptr)
				{
					delete Effect;
					Effect = nullptr;
				}
				Effect = new ParticleEffect();
				Vector2f MousePosition((float)Mouse::getPosition(window).x, (float)Mouse::getPosition(window).y);
				Effect->CreateParticleArray(MousePosition);


			}

		}
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update(sf::RenderWindow& window, float DeltaTime) {
	if (Effect != nullptr)
	{
		Effect->Update(DeltaTime);
	}
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render(sf::RenderWindow& window) {
	// This clears the window at the beginning of every frame
	window.clear();

	if (Effect != nullptr)
	{
		Effect->Draw(window);
	}
	//test.render(window);

	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}