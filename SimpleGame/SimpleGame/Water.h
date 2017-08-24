#include <iostream>
#include <SFML\Graphics.hpp>
#include "ColorScheme.h"

class Water 
{
public:
	Water();
	~Water();

	void drawWater(sf::RenderWindow &window);
	void animateWater();
	int getWaveIndices();

private:
	int waveIntensity;
	int waveIndices;
	bool up;
	sf::RectangleShape waterContent;
	sf::VertexArray waterLine;
	sf::VertexArray waterLine2;
};