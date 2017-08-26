#pragma once
#include <SFML\Graphics.hpp>

class Animal
{
public:
	Animal();
	~Animal();

	void drawAnimal(sf::RenderWindow &window);

	void innateBehavior(sf::Vector2f mouse, int waterLevel);
	void clickDetection(sf::Vector2f mouse);

private:
	sf::CircleShape anema;
	sf::Vector2f randomPoints;
	bool slowStart;
};