#pragma once
#include <SFML\Graphics.hpp>
#include "Utility.h"
#include "ColorScheme.h"

#define OFFSET 25

class Animal
{
public:
	Animal();
	~Animal();

	void drawAnimal(sf::RenderWindow &window);

	void innateBehavior(sf::Vector2f mouse, int waterLevel);
	void swim(int waterLevel);
	void clickDetection(sf::Vector2f mouse);
	void checkLegalState(sf::CircleShape &anema, int waterLevel);

private:
	bool soulSearching;
	int fishAmount = 1;
	sf::CircleShape anema[1];
	sf::Vector2f randomPoints;
	bool slowStart;
};