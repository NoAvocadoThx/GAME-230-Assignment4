#pragma once
//*****************************************************************
// GAME 230 assignment 4
// ParticleEffect.h
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "ShapeParticle.h"


using namespace sf;

class ParticleEffect
{
private:
	float Duration;

protected:
	int Size;
	ShapeParticle** ParticleArray;
	
public:
	ParticleEffect() 
	{ 
		Size = 30; 
		Duration = 10;
		ParticleArray = nullptr;
		
	};
	ParticleEffect(int Size);
	virtual ~ParticleEffect();
	void CreateParticleArray(Vector2f MousePosition);
	virtual ShapeParticle* CreateParticle(Vector2f MousePosition) = 0;
	void Update(float DeltaTime);
	void Draw(RenderWindow& Window);
	void Destroy();
	Vector2f Normalize(Vector2f& vec);

};