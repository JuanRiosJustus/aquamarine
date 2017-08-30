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
	int sandAmount = 200;
	sf::CircleShape sands[200];

	sf::RectangleShape sandContent;
	sf::VertexArray sandColor;
};