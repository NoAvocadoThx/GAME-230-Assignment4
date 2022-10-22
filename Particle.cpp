//*****************************************************************
// GAME 230 assignment 4
// Particle.cpp
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************

#include "Particle.h"

//*****************************************************************
Particle::Particle()
{
	Duration = PARTICLE_DURATION;
	ParticleSpeed = PARTICLE_SPEED;
}

//*****************************************************************
Particle::~Particle()
{

}

//*****************************************************************
void Particle::Setup(Vector2f MousePosition, Vector2f ParticleVelocity, float Speed, Color Color, float Duration)
{
	Circle.setRadius((float)(2+ (rand() % 7)));
	Position = MousePosition;
	Velocity = ParticleVelocity;
	ParticleColor = Color;
	//Duration = PARTICLE_DURATION;
	this->Duration = Duration;
	ParticleSpeed = Speed;

}

//*****************************************************************
void Particle::Update(float DeltaTime)
{
	Position.x = ParticleSpeed * Velocity.x * DeltaTime + Position.x;
	Position.y = ParticleSpeed * Velocity.y * DeltaTime + Position.y;
	Circle.setPosition(Position);
	Circle.setFillColor(ParticleColor);

	Duration -= DeltaTime;

}

//*****************************************************************
void Particle::Draw(RenderWindow& Window)
{
	Window.draw(Circle);
}

float Particle::GetDuration()
{
	return Duration;
}