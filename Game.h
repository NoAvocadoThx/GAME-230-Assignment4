// Our include guards
// These are critical for preventing collision related errors from a file accidentally getting fully included multiple times
//*****************************************************************
// GAME 230 assignment 4
// Game.h
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************

#ifndef GAME_H
#define GAME_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

#include "ExplosionParticleEffect.h"
#include "SnowParticleEffect.h"
#include "ParticleEffect.h"
#include "FireworksParticleEffect.h"

#include <vector>

 // Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {
	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	//template<typename T>

	class Game {
		
	private:
		
		std::vector<FireworksParticleEffect*> FireworksEffectsVector;

		ExplosionParticleEffect* ExplosionEffect = nullptr;
		SnowParticleEffect* SnowEffect = nullptr;
		//FireworksParticleEffect* FireworksEffect = nullptr;
		int EffectIndex = 0;
		const float DELAYTIME = 0.3f;
		int LoopCount = 0;
		const int MAXLOOPCOUNT = 10;
		float FireworkDelayTimer;
	public:
		/* Protoypes */
		// Constructor
		Game();
		// Game Loop Programming Pattern Methods
		void handleInput(sf::RenderWindow& window);
		void update(sf::RenderWindow& window, float DeltaTime);
		void render(sf::RenderWindow& window);
		// Destructor
		~Game();
		// Public variables
		bool isRepeating = false; //If the function need repeater for the Update function
	};
}

#endif