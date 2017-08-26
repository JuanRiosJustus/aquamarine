#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "ColorScheme.h"

#define PI 3.1415926535898

class Ground
{
public:
	Ground();
	~Ground();

	void drawGround(sf::RenderWindow &window);

private:
	int sandAmount = 100;
	sf::CircleShape sands[100];

	sf::RectangleShape sandContent;
	sf::VertexArray sandColor;
};