#include "Water.h"

Water::Water()
{
	// setting the primitive
	waterLine.setPrimitiveType(sf::LinesStrip);
	waterLine2.setPrimitiveType(sf::TrianglesStrip);

	// water to have things put
	waterContent.setSize(sf::Vector2f(1280.0f, 700.0f));
	waterContent.setFillColor(sf::Color(150.0f, 150.0f, 150.0f, 255.0f));
	waterContent.setPosition(sf::Vector2f(0.0f, 100.0f));

	// how rigid the wave will be 
	waveIntensity = 15;

	int waveIndices = 0;

	// to go up or not to
	up = true;
	// go across the whole screen
	int vertical_index = 100;
	for (int horizontal_index = 0; horizontal_index < sf::VideoMode::getDesktopMode().width; horizontal_index = horizontal_index + waveIntensity)
	{
		// add the point to the strip
		waterLine.append(sf::Vector2f(horizontal_index,vertical_index));
		waterLine2.append(sf::Vector2f(horizontal_index, vertical_index + 2));

		waterLine2[waveIndices].color = sf::Color(207.0f, 207.0f, 207.0f, 255.0f);
		waterLine[waveIndices].color = sf::Color(207.0f, 207.0f, 207.0f, 255.0f);

		// line goes upward
		if (up == true)
		{
			vertical_index = vertical_index + 5;
			if (vertical_index == 105)
			{
				up = false;
			}
		}

		// line goes downward
		if (up == false)
		{
			vertical_index = vertical_index - 5;
			if (vertical_index == 95)
			{
				up = true;
			}
		}
		waveIndices++;
		//std::cout << "the wave length " << waveLength << std::endl;
	}

	//player.setOrigin(50.0f, 50.0f);
	//player.setFillColor(sf::Color::Red);
	//player.setSize(sf::Vector2f(100.0f, 50.0f));
	//player.setPosition(300.0f, 300.0f);
}

Water::~Water()
{
}

void Water::drawWater(sf::RenderWindow &window)
{
	animateWater();
	window.draw(waterContent);
	window.draw(waterLine);
	window.draw(waterLine2);
}

void Water::animateWater()
{
	bool goingUp = true;

	int waveHeight;
	int waveHeight2;

	// go through the whole waterline array
	for (int index = 0; index < waterLine.getVertexCount(); index++)
	{
		waveHeight = waterLine[index].position.y;
		waveHeight2 = waterLine2[index].position.y;

		if (goingUp == true)
		{
			waveHeight = waveHeight + 2;
			waveHeight2 = waveHeight2 + 2;

			if (waveHeight >= 105)
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

			if (waveHeight <= 95)
			{
				goingUp = true;
				waveHeight = waterLine[index].position.y + 2;
				waveHeight2 = waterLine2[index].position.y + 2;
			}
		}

		// set the y position
		waterLine[index].position = sf::Vector2f(waterLine[index].position.x, waveHeight);
		waterLine2[index].position = sf::Vector2f(waterLine2[index].position.x, waveHeight2);
	}
}

int Water::getWaveIndices()
{
	return waveIndices;
}
