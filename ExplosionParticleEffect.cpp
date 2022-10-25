//*****************************************************************
// GAME 230 assignment 4
// ExplosionParticleEffect.cpp
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************

#include "ExplosionParticleEffect.h"

#include <random>

ExplosionParticleEffect::ExplosionParticleEffect()
{
	SingleParticle = nullptr;
}
ExplosionParticleEffect::~ExplosionParticleEffect()
{
	
}

CircleParticle& ExplosionParticleEffect::CreateParticle(Vector2f MousePosition)
{
	Vector2f Velocity(((float)(std::rand() % 1500 - 500)), ((float)(std::rand() % 1500 - 500)));
	//Velocity = Normalize(Velocity);
	SingleParticle = new CircleParticle(MousePosition,Velocity, 3, Color::White,1);
	return *SingleParticle;
}

void ExplosionParticleEffect::DestroyParticle(ShapeParticle* _ShapeParticle)
{
	delete _ShapeParticle;
	_ShapeParticle = nullptr;
}
