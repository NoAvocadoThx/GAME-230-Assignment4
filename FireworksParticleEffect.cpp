//*****************************************************************
// GAME 230 assignment 4
// FireworksParticleEffect.cpp
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************

#include "FireworksParticleEffect.h"

#include <random>

FireworksParticleEffect::FireworksParticleEffect()
{
	SingleParticle = nullptr;
}
FireworksParticleEffect::~FireworksParticleEffect()
{

}

ShapeParticle* FireworksParticleEffect::CreateParticle(Vector2f MousePosition)
{
	Vector2f Velocity(((float)(std::rand() % 1500 - 500)), ((float)(std::rand() % 1500)));
	Vector2f Position((float)(std::rand() % 500 - 250), (float)(std::rand() % 500 - 250));
	//Velocity = Normalize(Velocity);
	SingleParticle = new CircleParticle(MousePosition + Position, Velocity, 3, Color::White, 1);
	return SingleParticle;
}

