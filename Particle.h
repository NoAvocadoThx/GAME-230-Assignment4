//*****************************************************************
// GAME 230 assignment 4
// Particle.h
// Zhihao Wang
// Dennis Zabluda
// UCSC GPM FALL 2022
//*****************************************************************


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>

using namespace sf;

class Particle
{
private:

	CircleShape Circle;
	Vector2f	Position;
	Vector2f	Velocity;
	Color		ParticleColor;
	float		Duration = 0;
	float		ParticleSpeed;
	//float		Size;

	const float PARTICLE_SIZE = 3.0f;
	//const float PARTICLE_DURATION = 2.0f;
	float PARTICLE_DURATION;
	const float PARTICLE_SPEED = 105.0f;

public:
	Particle();
	~Particle();

	void Setup(Vector2f MousePostition, Vector2f ParticleVelocity, float Speed, Color Color, float Duration);
	void Update(float DeltaTime);
	void Draw(RenderWindow& Window);
	float GetDuration();
};