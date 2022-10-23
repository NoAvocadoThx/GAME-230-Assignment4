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

class Particle;
using namespace sf;

class ParticleEffect
{
private:

	static const int PARTICLE_ARRAY_SIZE = 90;
	Particle* ParticleArray[PARTICLE_ARRAY_SIZE] = { nullptr };

	float Duration;
public:
	ParticleEffect();
	~ParticleEffect();
	void CreateParticleArray(Vector2f MousePosition);
	void Update(float DeltaTime);
	void Draw(RenderWindow& Window);
	void Destroy();
	Vector2f Normalize(Vector2f& vec);

};