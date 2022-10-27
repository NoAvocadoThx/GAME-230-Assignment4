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
	Vector2f Velocity(((float)(std::rand() % 10 - 5)), ((float)(std::rand() % 10 - 5)));
	Vector2f Position((float)(std::rand() % 50 - 25), (float)(std::rand() % 50 - 25));
	//Velocity = Normalize(Velocity);

	Color color((float)(std::rand() % 255), (float)(std::rand() % 255), (float)(std::rand() % 255));
	SingleParticle = new CircleParticle(MousePosition + Position, Velocity, 3, color, 1);
	return SingleParticle;
}

