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
	virtual ~Particle();

	virtual const Vector2f GetPosition() const;
	virtual void SetPosition(const Vector2f Position);

	virtual const Vector2f GetVelocity() const;
	virtual void SetVelocity(const Vector2f Velocity);

	virtual const float GetLifeSpan() const;
	virtual void SetLifeSpan(const float LifeSpan);

	virtual const float GetLifeSpanRemaining() const;
	virtual void SetLifeSpanRemaining(const float RemainDuration);

	virtual const bool GetIsAlive() const;
	virtual void SetIsAlive(const bool IsAlive);

	

protected:
	virtual void Update(float DeltaTime);
	virtual void Draw(RenderWindow& Window) = 0;

	
};