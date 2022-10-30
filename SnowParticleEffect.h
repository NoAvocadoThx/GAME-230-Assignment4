#pragma once
//*****************************************************************
// GAME 230 assignment 4
// SnowParticleEffect.h
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************
#include "CircleParticle.h"
#include "ParticleEffect.h"

class SnowParticleEffect : public ParticleEffect
{
public:
	SnowParticleEffect();
	SnowParticleEffect(int Size);
	~SnowParticleEffect();
	ShapeParticle* CreateParticle(Vector2f MousePosition);
	//void CreateLoopingParticleArray(Vector2f MousePosition);
	void Update(float DeltaTime);
	Vector2f Position;
	
private:
	CircleParticle* SingleParticle;
};