// We need to include our header file to implement the function prototypes of our Game class
//*****************************************************************
// GAME 230 assignment 4
// Game.cpp
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************
#include "Game.h"
#include <iostream>
#include <random>

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() {
	//test.setPosition(Vector2f(400, 300));
	//test.setSize(50);
	FireworkDelayTimer = DELAYTIME;
}

// Implements private funtion that delay for the purpose of looping
void Game::delayFor(float seconds) {
	int x = 0;
	while (x < seconds * 10000) {
		++x;
	}
}

// Implements private fuction that use vector and repeat the effects
void Game::repeatingEffects() {

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
				Vector2f MousePosition((float)Mouse::getPosition(window).x, (float)Mouse::getPosition(window).y);

				if (ExplosionEffect != nullptr)
				{
					delete ExplosionEffect;
					ExplosionEffect = nullptr;
				}
				if (SnowEffect != nullptr)
				{
					delete SnowEffect;
					SnowEffect = nullptr;
				}
				
				for (FireworksParticleEffect* effect : FireworksEffectsVector) {
					if (effect != nullptr)
					{
						//FireworksEffectsVector.erase(FireworksEffectsVector.begin());
						if (effect != nullptr)
						{
							delete effect;
							effect = nullptr;
						}
					}
				}
				FireworksEffectsVector.clear();
				FireworksParticleEffect* effect = nullptr;
				switch (EffectIndex)
				{

				case 0:
					ExplosionEffect = new ExplosionParticleEffect(100);
					ExplosionEffect->CreateParticleArray(MousePosition);
					break;
				case 1:
					SnowEffect = new SnowParticleEffect(300);
					SnowEffect->CreateParticleArray(MousePosition);
					break;
				case 2:
			
					isRepeating = true;
					
					//delete FireworksEffect;

					break;
				default:
					break;
				}			
			}
		}

		if (event.type == Event::KeyReleased) 
		{
			switch (event.key.code)
			{
			case Keyboard::Num1:
				EffectIndex = 0;
				break;
			case Keyboard::Num2:
				EffectIndex = 1;
				break;
			case Keyboard::Num3:
				EffectIndex = 2;
				break;
			default:
				EffectIndex = 0;
				break;
			}
		}
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update(sf::RenderWindow& window, float DeltaTime) {
	if (ExplosionEffect != nullptr)
	{
		ExplosionEffect->Update(DeltaTime);
	}
	if (SnowEffect != nullptr)
	{
		SnowEffect->Update(DeltaTime);
	}
	for (FireworksParticleEffect* effect : FireworksEffectsVector) {
		if (effect != nullptr)
		{
			effect->Update(DeltaTime);
		}
		//if (effect)
	}
	
	Vector2f MousePosition((float)Mouse::getPosition(window).x, (float)Mouse::getPosition(window).y);

	if (isRepeating) {
		switch (EffectIndex)
		{
		case 2:
			if (LoopCount == MAXLOOPCOUNT) {
				isRepeating = false;
				LoopCount = 0;
			
				break;
			}

			FireworkDelayTimer -= DeltaTime;
			if (LoopCount > FireworksEffectsVector.size()) LoopCount = 0;
			if (FireworkDelayTimer <= 0 )
			{
				FireworksEffectsVector.push_back(new FireworksParticleEffect());
				Vector2f Position((float)(std::rand() % 300 - 150), (float)(std::rand() % 300 - 150));
				FireworksEffectsVector[LoopCount]->CreateParticleArray(MousePosition + Position);
				
				std::cout << "Create Fireworks " << LoopCount << std::endl;
				++LoopCount;
				FireworkDelayTimer = DELAYTIME;
			}

			break;
		default:
			break;
		}
	}

}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render(sf::RenderWindow& window) {
	// This clears the window at the beginning of every frame
	
	window.clear();
	if (ExplosionEffect != nullptr)
	{
		
		ExplosionEffect->Draw(window);
	}
	if (SnowEffect != nullptr)
	{
		
		SnowEffect->Draw(window);
	}
	for (FireworksParticleEffect* effect : FireworksEffectsVector) {
		if (effect != nullptr)
		{
			effect->Draw(window);
		}
	}

	//test.render(window);

	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() 
{
	if (ExplosionEffect != nullptr) delete ExplosionEffect;
	if (SnowEffect != nullptr) delete SnowEffect;
	for (FireworksParticleEffect* effect : FireworksEffectsVector) {
		if (effect != nullptr) delete effect;	
	}
}