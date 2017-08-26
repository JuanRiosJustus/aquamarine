#include "Animal.h"

Animal::Animal()
{
	slowStart = true;
	anema.setRadius(15);
	anema.setPosition(sf::Vector2f(400, 400));
	anema.setFillColor(sf::Color(150, 150, 150, 255));
	anema.setOutlineColor(sf::Color(207, 207, 207, 255));
	anema.setOutlineThickness(3);
	anema.setOrigin(anema.getRadius(), anema.getRadius());
}

Animal::~Animal()
{
}

void Animal::drawAnimal(sf::RenderWindow &window)
{
	window.draw(anema);
}

void Animal::innateBehavior(sf::Vector2f mouse, int waterLevel)
{
	// TODO SWAP RANDOMPOINTS WITH MOUSE OR VICE VERCE
	randomPoints.x = mouse.x;
	randomPoints.y = mouse.y;



	// ALTERING THE ANIMALS X SPEED
	if (anema.getPosition().x < randomPoints.x)
	{
		anema.setPosition(sf::Vector2f(anema.getPosition().x + 0.4f, anema.getPosition().y));
	}
	if (anema.getPosition().x > randomPoints.x)
	{
		anema.setPosition(sf::Vector2f(anema.getPosition().x - 0.4f, anema.getPosition().y));
	}

	// ALTERING ANIMALS Y SPEED
	if (anema.getPosition().y < randomPoints.y)
	{
		anema.setPosition(sf::Vector2f(anema.getPosition().x, anema.getPosition().y + 0.4f));
	}
	if (anema.getPosition().y > randomPoints.y)
	{
		anema.setPosition(sf::Vector2f(anema.getPosition().x, anema.getPosition().y - 0.4f));

		// make sure they dont go above sea level
		if (anema.getPosition().y <= 100)
		{
			anema.setPosition(sf::Vector2f(anema.getPosition().x, 120));
		}
	}
}

void Animal::clickDetection(sf::Vector2f mouse)
{
}