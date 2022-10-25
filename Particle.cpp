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
		if (this != nullptr)
		{
			//delete this;
			
		}
	}
}


//*****************************************************************
Vector2f Particle::GetPosition()
{
	return Position;
}
//*****************************************************************
void Particle::SetPosition(Vector2f _Position)
{
	Position = _Position;
}
//*****************************************************************
Vector2f  Particle::GetVelocity()
{
	return Velocity;
}
//*****************************************************************
void  Particle::SetVelocity(Vector2f _Velocity)
{
	Velocity = _Velocity;
}
//*****************************************************************
float Particle::GetLifeSpan()
{
	return Duration;
}
//*****************************************************************
void Particle::SetLifeSpan(float LifeSpan)
{
	Duration = LifeSpan;
}

//*****************************************************************
float Particle::GetLifeSpanRemaining()
{
	return Timer;
}
//*****************************************************************
void Particle::SetLifeSpanRemaining(float RemainDuration)
{
	Timer = RemainDuration;
}

//*****************************************************************
bool Particle::GetIsAlive()
{
	return IsAlive;
}
//*****************************************************************
void Particle::SetIsAlive(bool _IsAlive)
{
	IsAlive = _IsAlive;
}