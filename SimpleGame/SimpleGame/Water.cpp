#include "Water.h"

/*
* The constructor.
*/
Water::Water()
{
	// water height
	waterLevel = 100;

	// setting the primitive
	waterLine.setPrimitiveType(sf::LinesStrip);
	waterLine2.setPrimitiveType(sf::TrianglesStrip);

	// water to have things put
	waterContent.setSize(sf::Vector2f(1280.0f, 700.0f));
	waterContent.setFillColor(ColorScheme::bodyOfWaterColor());
	waterContent.setPosition(sf::Vector2f(0.0f, waterLevel));

	// how rigid the wave will be 
	waveIntensity = 15;
	int waveIndices = 0;
	up = true;

	// go across the whole screen
	int vertical_index = 100;
	for (int horizontal_index = 0; horizontal_index < sf::VideoMode::getDesktopMode().width; horizontal_index = horizontal_index + waveIntensity)
	{
		// add the point to the strip
		waterLine.append(sf::Vector2f(horizontal_index, waterLevel));
		waterLine2.append(sf::Vector2f(horizontal_index, waterLevel + 2));

		waterLine2[waveIndices].color = ColorScheme::getMidWhite();
		waterLine[waveIndices].color = ColorScheme::getMidWhite();

		// Line goes upward.
		if (up == true)
		{
			vertical_index = vertical_index + 5;
			if (vertical_index == waterLevel + 5) { up = false; }
		}

		// Line goes downward.
		if (up == false)
		{
			vertical_index = vertical_index - 5;
			if (vertical_index == waterLevel - 5) { up = true; }
		}
		waveIndices++;
	}
}

/*
* Draws all the water and objets below the water to the screen on the main window.
*
* @param &window - Main window to draw things to.
* @param mouse - The mouse position to the window/screen.
*/
void Water::drawWater(sf::RenderWindow &window, sf::Vector2f mouse)
{
	animateWater();
	window.draw(waterColor);
	bubbles.generateBubbles(window, waterLevel);
	animals.innateBehavior(mouse, waterLevel);
	animals.drawAnimal(window);
	
	ground.drawGround(window);
	window.draw(waterContent);
	window.draw(waterLine);
	window.draw(waterLine2);
}

/**
* This method animates the water level going upward and downward.
*/
void Water::animateWater()
{
	bool goingUp = true;
	int waveHeight;
	int waveHeight2;

	for (int index = 0; index < waterLine.getVertexCount(); index++)
	{
		waveHeight = waterLine[index].position.y;
		waveHeight2 = waterLine2[index].position.y;

		if (goingUp == true)
		{
			waveHeight = waveHeight + 2;
			waveHeight2 = waveHeight2 + 2;

			if (waveHeight >= waterLevel + 5)
			{
				goingUp = false;
				waveHeight = waterLine[index].position.y - 2;
				waveHeight2 = waterLine2[index].position.y - 2;
			}
		}

		if (goingUp == false)
		{
			waveHeight = waveHeight - 2;
			waveHeight2 = waveHeight2 - 2;

			if (waveHeight <= waterLevel - 5)
			{
				goingUp = true;
				waveHeight = waterLine[index].position.y + 2;
				waveHeight2 = waterLine2[index].position.y + 2;
			}
		}
		waterLine[index].position = sf::Vector2f(waterLine[index].position.x, waveHeight);
		waterLine2[index].position = sf::Vector2f(waterLine2[index].position.x, waveHeight2);
	}
}
// Returns the amount of waves indices.
int Water::getWaveIndices() { return waveIndices; }
// Returns the water level.
int Water::getWaterLevel() { return waterLevel; }
// Sets the water level.
void Water::setWaterLevel(int level) { waterLevel = level; waterContent.setPosition(sf::Vector2f(0.0f, waterLevel)); }
// Deconstructor.
Water::~Water() { }