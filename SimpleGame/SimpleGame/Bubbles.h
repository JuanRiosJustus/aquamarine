#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>


class Bubbles
{
public:
	Bubbles();
	~Bubbles();

	void generateBubbles(sf::RenderWindow &window);
	void animateBubbles(int frequancy);

private:
	int amountOfBubbles = 20;
	float bubbleHeight;
	sf::CircleShape bubbles[20];
};