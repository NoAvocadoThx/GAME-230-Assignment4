#pragma once
//*****************************************************************
// GAME 230 assignment 4
// ShapeParticle.h
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************

#include "Particle.h"

using namespace sf;

class ShapeParticle : public Particle 
{
public:
	ShapeParticle() { Shape_P = nullptr; }
	ShapeParticle(Vector2f MousePosition, Vector2f ParticleVelocity, float Speed, Color Color, float Duration);
	~ShapeParticle();

	virtual void Update(float DeltaTime);
	virtual void Draw(RenderWindow& Window) = 0;
	virtual Shape* GetShape();
protected:
	

	Shape* Shape_P;
	
};