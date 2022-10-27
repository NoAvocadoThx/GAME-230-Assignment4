//*****************************************************************
// GAME 230 assignment 4
// ParticleEffect.cpp
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************



#include "CircleParticle.h"
#include "Particle.h"
#include "ParticleEffect.h"
#include <random>

//*****************************************************************
ParticleEffect::ParticleEffect(int _Size)
{
	Duration = 10;
	Size = _Size;
	ParticleArray = nullptr;
}

//*****************************************************************
ParticleEffect::~ParticleEffect()
{
	//Destroy();
	
	for (int i = 0; i < Size; i++)
	{
		if (ParticleArray[i] != nullptr)
		{
			delete ParticleArray[i];
			ParticleArray[i] = nullptr;
		}
	}
	delete[] ParticleArray;
	ParticleArray = nullptr;
}

//*****************************************************************
void ParticleEffect::CreateParticleArray(Vector2f MousePosition)
{

	ParticleArray = new ShapeParticle*[Size];
	for (int i = 0; i < Size; i++)
	{
		
		ParticleArray[i] = CreateParticle(MousePosition);
	}
	Duration = 10;

}

//*****************************************************************
void ParticleEffect::Update(float DeltaTime)
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
	}


}
//*****************************************************************
void ParticleEffect::Draw(RenderWindow& Window)
{
	for (int i = 0; i < Size; i++)
	{
		if (ParticleArray[i] != nullptr && ParticleArray[i]->GetIsAlive())
		{
			ParticleArray[i]->Draw(Window);
		}
	}
}

//*****************************************************************
Vector2f ParticleEffect::Normalize(Vector2f& vec)
{
	float Length = sqrt(vec.x * vec.x + vec.y * vec.y);

	return Length == 0 ? vec : Vector2f(vec.x / Length, vec.y / Length);
}

//*****************************************************************
void ParticleEffect::Destroy()
{
	
}