#pragma once
//*****************************************************************
// GAME 230 assignment 4
// CircleParticle.h
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************

#include "ShapeParticle.h"

class CircleParticle : public ShapeParticle
{
private:
	float Radius;
	CircleShape Circle;
public:
	CircleParticle() { Radius = 5; }
	CircleParticle(Vector2f MousePosition, Vector2f ParticleVelocity, float Speed, Color Color, float Duration);
	~CircleParticle();
	void Update(float DeltaTime);
	void Draw(RenderWindow& Window);
	const float GetRadius() const;
	void SetRadius(const float _Radius);
};