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

SnowParticleEffect::SnowParticleEffect(int Size) : ParticleEffect(Size)
{
	SingleParticle = nullptr;
}
SnowParticleEffect::~SnowParticleEffect()
{

}

ShapeParticle* SnowParticleEffect::CreateParticle(Vector2f MousePosition)
{
	Vector2f Velocity(0, ((float)(std::rand() % 500)));
	Vector2f Position((float)(std::rand() % 500 - 250), 0);
	//Velocity = Normalize(Velocity);
	this->Position = MousePosition;
	SingleParticle = new CircleParticle(MousePosition + Position, Velocity, 1, Color::White, 1);
	dynamic_cast<CircleParticle*>(SingleParticle)->SetRadius(1);
	float RandomDuration((float)(std::rand() % 10));
	SingleParticle->SetLifeSpanRemaining(RandomDuration);
	return SingleParticle;
}

void SnowParticleEffect::Update(float DeltaTime)
{

	for (int i = 0; i < Size; i++)
	{
		if (ParticleArray[i] != nullptr)
		{
			ParticleArray[i]->Update(DeltaTime);

			if (ParticleArray[i]->GetLifeSpanRemaining() <= 0)
			{
				delete ParticleArray[i];
				ParticleArray[i] = nullptr;

			}
		}
		else if (ParticleArray[i] == nullptr)
		{
			ParticleArray[i] = this->CreateParticle(this->Position);			
		}
	}
}

