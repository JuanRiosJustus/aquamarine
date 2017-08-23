#include "Bubbles.h"

Bubbles::Bubbles()
{
	srand((unsigned)time(NULL));
	
	for (int index = 0; index < amountOfBubbles; index++)
	{
		bubbles[index].setRadius((rand() % static_cast<int>(20 + 1)));
		bubbles[index].setFillColor(sf::Color(150, 150, 150, 255));
		bubbles[index].setOutlineColor(sf::Color(207, 207, 207, 255));
		bubbles[index].setOutlineThickness(2);
		bubbles[index].setPosition(sf::Vector2f((rand() % static_cast<int>(1280 + 1)), 720));
	}
}

Bubbles::~Bubbles()
{
}

void Bubbles::generateBubbles(sf::RenderWindow &window)
{
	animateBubbles(1000);
	for (int index = 0; index < amountOfBubbles; index++)
	{
		
		window.draw(bubbles[index]);
	}
}

void Bubbles::animateBubbles(int frequancy)
{

	// higher the frequancy - more spread out the bubbles

	// for each bubble
	for (int index = 0; index < amountOfBubbles; index++)
	{
		// create a random speed of increase
		bubbleHeight = bubbles[index].getPosition().y;
		bubbleHeight = bubbleHeight - (((float)rand() / (float)RAND_MAX) * 2);

		// when the bubble reaches its max height
		if (bubbleHeight <= 100)
		{
			// bring bubble to randomized height
			bubbleHeight = ((rand() % static_cast<int>(frequancy) + 720));

			// adjuest bubbles horizontal spawn location
			bubbles[index].setPosition(sf::Vector2f((rand() % static_cast<int>(1280 + 1)), bubbles[index].getPosition().y));

		}

		// ater the bubbles position
		bubbles[index].setPosition(sf::Vector2f(bubbles[index].getPosition().x, bubbleHeight));
	}
}
