#pragma once
//*****************************************************************
// GAME 230 assignment 4
// ExplosionParticleEffect.h
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************
#include "CircleParticle.h"
#include "ParticleEffect.h"

class ExplosionParticleEffect : public ParticleEffect
{
public:
	ExplosionParticleEffect();
	~ExplosionParticleEffect();
	CircleParticle& CreateParticle(Vector2f MousePosition);
	void DestroyParticle(ShapeParticle*);
private:
	CircleParticle* SingleParticle;
};