#pragma once
//*****************************************************************
// GAME 230 assignment 4
// Particle.h
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>

using namespace sf;

class Particle
{
private:
	Vector2f	Position;
	Vector2f	Velocity;
	Color		ParticleColor;
	float		Duration = 0;
	float		Timer = 0;
	float		ParticleSpeed;
	bool        IsAlive;

public:
	Particle();
	Particle(Vector2f MousePostition, Vector2f ParticleVelocity, float Speed, Color Color, float Duration);
	~Particle();

	virtual Vector2f GetPosition();
	virtual void SetPosition(Vector2f Position);

	virtual Vector2f GetVelocity();
	virtual void SetVelocity(Vector2f Velocity);

	virtual float GetLifeSpan();
	virtual void SetLifeSpan(float LifeSpan);

	virtual float GetLifeSpanRemaining();
	virtual void SetLifeSpanRemaining(float RemainDuration);

	virtual bool GetIsAlive();
	virtual void SetIsAlive(bool IsAlive);

	

protected:
	virtual void Update(float DeltaTime);
	virtual void Draw(RenderWindow& Window) = 0;

	
};