#pragma once
//*****************************************************************
// GAME 230 assignment 4
// FireworksParticleEffect.h
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************
#include "CircleParticle.h"
#include "ParticleEffect.h"

class FireworksParticleEffect : public ParticleEffect
{
public:
	FireworksParticleEffect();
	~FireworksParticleEffect();
	ShapeParticle* CreateParticle(Vector2f MousePosition);
private:
	CircleParticle* SingleParticle;
};