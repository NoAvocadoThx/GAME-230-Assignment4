//*****************************************************************
// GAME 230 assignment 4
// CircleParticle.cpp
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************

#include "CircleParticle.h"

CircleParticle::CircleParticle(Vector2f MousePosition, Vector2f ParticleVelocity, float Speed, Color Color, float Duration) : ShapeParticle(MousePosition, ParticleVelocity, Speed, Color, Duration)
{

	Radius = 5;
	Circle.setRadius(Radius);
	Circle.setFillColor(Color);
	Shape_P = &Circle;
	
	
	
}
//*****************************************************************

CircleParticle::~CircleParticle()
{

}
//*****************************************************************

void CircleParticle::Update(float DeltaTime)
{
	this->SetPosition( Vector2f( this->GetVelocity().x * DeltaTime + this->GetPosition().x, this->GetVelocity().y * DeltaTime + this->GetPosition().y));

	Circle.setPosition(this->GetPosition());
	Circle.setRadius(Radius);
	ShapeParticle::Update(DeltaTime);
}
//*****************************************************************

void CircleParticle::Draw(RenderWindow& Window)
{
	Window.draw(Circle);
}
//*****************************************************************

const float CircleParticle::GetRadius() const
{
	return Radius;
}
//*****************************************************************

void CircleParticle::SetRadius(const float _Radius)
{
	Radius = _Radius;
	
}