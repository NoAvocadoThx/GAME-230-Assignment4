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
	Destroy();
	delete[] ParticleArray;
	ParticleArray = nullptr;
	
}

//*****************************************************************
void ParticleEffect::CreateParticleArray(Vector2f MousePosition)
{
	/*for (int i = 0; i < PARTICLE_ARRAY_SIZE; i++)
	{
		Particle* SingleParticle = new Particle();
		Vector2f Velocity( ((float)(std::rand() % 1500 - 500)), ((float)(std::rand() % 1500 - 500)));
		Velocity = Normalize(Velocity);
		Vector3f RGB((float)(std::rand() % 225), (float)(std::rand() % 225), (float)(std::rand() % 225));
		Color Color((Uint8)RGB.x, (Uint8)RGB.y, (Uint8)RGB.z);
		SingleParticle->Setup(MousePosition, Velocity, (float)(40 + (rand() % 60)), Color, (float)(std::rand() % 4));
		ParticleArray[i] = SingleParticle;
	}*/

	ParticleArray = new ShapeParticle*[Size];
	for (int i = 0; i < Size; i++)
	{
		ParticleArray[i] = &CreateParticle(MousePosition);
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
				DestroyParticle(ParticleArray[i]);
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
	for (int i = 0; i < Size; i++)
	{
		if (ParticleArray[i] != nullptr)
		{
			delete ParticleArray[i];
			ParticleArray[i] = nullptr;
		}
	}
}