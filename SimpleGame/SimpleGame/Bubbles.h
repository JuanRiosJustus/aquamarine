#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "ColorScheme.h"


class Bubbles
{
public:
	Bubbles();
	~Bubbles();

	void generateBubbles(sf::RenderWindow &window);
	void animateBubbles(int frequancy);
	void clickDetection(sf::Vector2f mouse);

private:
	int amountOfBubbles = 20;
	int frequancy;
	float bubbleHeight;
	sf::CircleShape bubbles[20];
};