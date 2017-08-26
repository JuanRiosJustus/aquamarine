#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "ColorScheme.h"
#include "Ground.h"

class Water
{
public:
	Water();
	~Water();

	void drawWater(sf::RenderWindow &window);
	void animateWater();
	int getWaveIndices();
	int getWaterLevel();
	void setWaterLevel(int level);

private:
	int waveIntensity;
	int waveIndices;
	bool up;
	int waterLevel;
	Ground ground;
	sf::RectangleShape waterContent;
	sf::VertexArray waterColor;
	sf::VertexArray waterLine;
	sf::VertexArray waterLine2;
};