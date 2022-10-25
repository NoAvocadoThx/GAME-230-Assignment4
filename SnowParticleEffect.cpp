//*****************************************************************
// GAME 230 assignment 4
// SnowParticleEffect.cpp
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************

#include "SnowParticleEffect.h"

#include <random>

SnowParticleEffect::SnowParticleEffect()
{
	SingleParticle = nullptr;
}
SnowParticleEffect::~SnowParticleEffect()
{

}

CircleParticle& SnowParticleEffect::CreateParticle(Vector2f MousePosition)
{
	Vector2f Velocity(0, ((float)(std::rand() % 1500)));
	Vector2f Position((float)(std::rand() % 500 - 250), 0);
	//Velocity = Normalize(Velocity);
	SingleParticle = new CircleParticle(MousePosition + Position, Velocity, 3, Color::White, 1);
	return *SingleParticle;
}

void SnowParticleEffect::DestroyParticle(ShapeParticle* _ShapeParticle)
{
	delete _ShapeParticle;
	_ShapeParticle = nullptr;
}