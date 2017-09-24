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
	/* Draws the water and every object under waterline repective of waterLevel */
	void drawWater(sf::RenderWindow &window, sf::Vector2f mouse);
	/* Animates waves */
	void animateWater();

	// Accessors
	int getWaveIndices();
	int getWaterLevel();
	void setWaterLevel(int level);

private:
	int waveIntensity;
	int waveIndices;
	bool up;
	int waterLevel;

	Animal animals;
	Bubbles bubbles;
	Ground ground;
	sf::RectangleShape waterContent;
	sf::VertexArray waterColor;
	sf::VertexArray waterLine;
	sf::VertexArray waterLine2;
};