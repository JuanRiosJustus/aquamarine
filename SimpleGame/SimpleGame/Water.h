#include <iostream>
#include <SFML\Graphics.hpp>

class Water 
{
public:
	Water();
	~Water();

	void drawWater(sf::RenderWindow &window);
	void animateWater();
	int getWaveIndices();
	//void movePlayer(char direction);
	//float latitude();
	//float longitude();

private:
	int waveIntensity;
	int waveIndices;
	bool up;
	sf::RectangleShape waterContent;
	sf::VertexArray waterLine;
	sf::VertexArray waterLine2;
};