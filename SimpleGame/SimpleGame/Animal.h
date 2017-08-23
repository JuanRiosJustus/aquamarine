#pragma once
#include <SFML\Graphics.hpp>

class Animal
{
public:
	Animal();
	~Animal();

	void drawAnimal(sf::RenderWindow &window);

	void innateBehavior(sf::Vector2f vector);

private:
	sf::CircleShape anema;
	sf::Vector2f point;
	bool slowStart;
};