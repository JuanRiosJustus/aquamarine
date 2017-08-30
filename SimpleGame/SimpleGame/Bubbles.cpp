#include "Bubbles.h"
#include "math.h"

Bubbles::Bubbles()
{
	frequancy = 1000;
	srand((unsigned)time(NULL));

	for (int index = 0; index < amountOfBubbles; index++)
	{
		bubbles[index].setRadius((rand() % static_cast<int>(15 + 1)));
		bubbles[index].setFillColor(ColorScheme::bubbleColor());
		bubbles[index].setOutlineColor(sf::Color(207, 207, 207, 130));
		bubbles[index].setOutlineThickness(2);
		bubbles[index].setOrigin(bubbles[index].getRadius(), bubbles[index].getRadius());
		bubbles[index].setPosition(sf::Vector2f((rand() % static_cast<int>(1280 + 1)), 720));
	}
}

Bubbles::~Bubbles()
{
}

void Bubbles::generateBubbles(sf::RenderWindow &window, int waterLevel)
{
	animateBubbles(frequancy, waterLevel);
	for (int index = 0; index < amountOfBubbles; index++)
	{

		window.draw(bubbles[index]);
	}
}

void Bubbles::animateBubbles(int frequancy, int waterLevel)
{

	// waterlevel for bubble height

	// higher the frequancy - more spread out the bubbles

	// for each bubble
	for (int index = 0; index < amountOfBubbles; index++)
	{
		// create a random speed of increase
		bubbleHeight = bubbles[index].getPosition().y;
		bubbleHeight = bubbleHeight - (((float)rand() / (float)RAND_MAX) * 2);

		// when the bubble reaches its max height
		if (bubbleHeight <= waterLevel + 20)
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


void Bubbles::clickDetection(sf::Vector2f mouse)
{
	sf::Vector2f box;
	float bubbleRadius;

	for (int index = 0; index < amountOfBubbles; index++)
	{
		box.x = bubbles[index].getPosition().x;
		box.y = bubbles[index].getPosition().y;
		bubbleRadius = bubbles[index].getRadius();

		// while the moust is inclusively between the box
		if (mouse.x >= box.x - bubbleRadius && mouse.x <= box.x + bubbleRadius && mouse.y >= box.y - bubbleRadius && mouse.y <= box.y + bubbleRadius)
		{
			// utility check
			std::cout << "bubble clicked " << std::endl;

			// adjuest bubbles horizontal spawn location
			bubbles[index].setPosition(sf::Vector2f((rand() % static_cast<int>(1280 + 1)), ((rand() % static_cast<int>(1000) + 720))));
			// make it a random color //TODO
			bubbles[index].setFillColor(ColorScheme::getInterimBlue());
			goto done;
		}
	}
	done:;
}

sf::CircleShape Bubbles::getBubbles(int index)
{
	return bubbles[index];
}
