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
	Duration = 1;
	Timer = Duration;
	ParticleSpeed = 0;
	IsAlive = false;
}

//*****************************************************************
Particle::Particle(Vector2f MousePosition, Vector2f ParticleVelocity, float Speed, Color Color, float Duration)
{
	Position = MousePosition;
	Velocity = ParticleVelocity;
	ParticleColor = Color;
	this->Duration = Duration;
	ParticleSpeed = Speed; 
	IsAlive = true;
	Timer = Duration;
}

//*****************************************************************
Particle::~Particle()
{

	Duration = 0;
	ParticleSpeed = 0;
	IsAlive = false;
	Timer = Duration;
}


//*****************************************************************
void Particle::Update(float DeltaTime)
{

	Timer -= DeltaTime;
	if (Timer <= 0)
	{
		IsAlive = false;

	}
}


//*****************************************************************
const Vector2f Particle::GetPosition() const
{
	return Position;
}
//*****************************************************************
void Particle::SetPosition(const Vector2f _Position)
{
	Position = _Position;
}
//*****************************************************************
const Vector2f  Particle::GetVelocity() const
{
	return Velocity;
}
//*****************************************************************
void  Particle::SetVelocity(const Vector2f _Velocity)
{
	Velocity = _Velocity;
}
//*****************************************************************
const float Particle::GetLifeSpan() const
{
	return Duration;
}
//*****************************************************************
void Particle::SetLifeSpan(const float LifeSpan)
{
	Duration = LifeSpan;
}

//*****************************************************************
const float Particle::GetLifeSpanRemaining() const
{
	return Timer;
}
//*****************************************************************
void Particle::SetLifeSpanRemaining(const float RemainDuration)
{
	Timer = RemainDuration;
}

//*****************************************************************
const bool Particle::GetIsAlive() const
{
	return IsAlive;
}
//*****************************************************************
void Particle::SetIsAlive(const bool _IsAlive)
{
	IsAlive = _IsAlive;
}