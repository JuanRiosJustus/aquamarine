#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "ColorScheme.h"
#include "Ground.h"
#include "Bubbles.h"
#include "Animal.h"
#include "Bubbles.h"

class Water
{
public:
	Water();
	~Water();

	void drawWater(sf::RenderWindow &window, sf::Vector2f mouse);
	void animateWater();
	int getWaveIndices();
	int getWaterLevel();
	void setWaterLevel(int level);

private:
	Animal animals;
	int waveIntensity;
	int waveIndices;
	bool up;
	int waterLevel;
	Bubbles bubbles;
	Ground ground;
	sf::RectangleShape waterContent;
	sf::VertexArray waterColor;
	sf::VertexArray waterLine;
	sf::VertexArray waterLine2;
};