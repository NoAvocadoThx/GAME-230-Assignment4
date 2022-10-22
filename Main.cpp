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
#include "ParticleEffect.h"

using namespace sf;

void HandleInput(RenderWindow& Window, Event& event);
void Update(float DeltaTime);
void Draw(RenderWindow& Window);

ParticleEffect* Effect = nullptr;

//*****************************************************************
int main()
{

	RenderWindow Window(VideoMode(1000, 1000), "Game 230 Assignment 3");
	Window.setFramerateLimit(60);
	Clock deltaClock;


	while (Window.isOpen())
	{
		Window.clear();
		Event event;
		Time dt = deltaClock.restart();
		while (Window.pollEvent(event))
		{
			
			HandleInput(Window, event);
			
			
		}
		Update(dt.asSeconds());
		Draw(Window);
		Window.display();
	}

	return 0;
}

//*****************************************************************
void HandleInput(RenderWindow& Window, Event& event)
{
	if (event.type == Event::Closed)
		Window.close();

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
			Vector2f MousePosition((float)Mouse::getPosition(Window).x, (float)Mouse::getPosition(Window).y);
			Effect->CreateParticleArray(MousePosition);


		}

	}
}

//*****************************************************************
void Update(float DeltaTime)
{
	if (Effect != nullptr)
	{
		Effect->Update(DeltaTime);
	}
	
}

//*****************************************************************
void Draw(RenderWindow& Window)
{
	if (Effect != nullptr)
	{
		Effect->Draw(Window);
	}
}
