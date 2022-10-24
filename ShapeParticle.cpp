#pragma once
//*****************************************************************
// GAME 230 assignment 4
// ShapeParticle.cpp
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************

#include "ShapeParticle.h"

//*****************************************************************
ShapeParticle::ShapeParticle(Vector2f MousePosition, Vector2f ParticleVelocity, float Speed, Color Color, float Duration) : Particle(MousePosition, ParticleVelocity, Speed, Color, Duration)
{
	Shape_P = nullptr;
}

//*****************************************************************
ShapeParticle::~ShapeParticle()
{
	
}

//*****************************************************************
void ShapeParticle::Update(float DeltaTime)
{
	Particle::Update(DeltaTime);
}

//*****************************************************************
Shape* ShapeParticle::GetShape()
{
	return Shape_P;
}

