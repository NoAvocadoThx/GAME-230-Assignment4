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


ExplosionParticleEffect::ExplosionParticleEffect(int Size) : ParticleEffect(Size)
{
	SingleParticle = nullptr;
}

ExplosionParticleEffect::~ExplosionParticleEffect()
{

}

ShapeParticle* ExplosionParticleEffect::CreateParticle(Vector2f MousePosition)
{
	Vector2f Velocity(((float)(std::rand() % 1500 - 500)), ((float)(std::rand() % 1500 - 500)));
	//Velocity = Normalize(Velocity);
	SingleParticle = new CircleParticle(MousePosition,Velocity, 2, Color::Yellow,3);
	return SingleParticle;
}

