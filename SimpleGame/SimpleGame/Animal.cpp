#include "Animal.h"

Animal::Animal()
{
	soulSearching = true;

	//TODO
	for (int count = 0; count < fishAmount; count++)
	{
		anema[count].setPointCount(3);
		anema[count].setRotation(90);
		anema[count].setRadius(15);
		anema[count].setPosition(sf::Vector2f(400, 400));
		anema[count].setFillColor(sf::Color::Yellow);
		anema[count].setOutlineColor(sf::Color(207, 207, 207, 255));
		anema[count].setOutlineThickness(2);
		anema[count].setOrigin(anema[count].getRadius(), anema[count].getRadius());
		anema[count].setPosition(sf::Vector2f((rand() % static_cast<int>(-400) - 400), rand() % static_cast<int>(-200) - 1220));

	}
}

Animal::~Animal()
{
}

void Animal::drawAnimal(sf::RenderWindow &window)
{

	//TODO
	for (int index = 0; index < fishAmount; index++)
	{
		window.draw(anema[index]);
	}
}

void Animal::innateBehavior(sf::Vector2f mouse, int waterLevel)
{
	// TODO SWAP RANDOMPOINTS WITH MOUSE OR VICE VERCE

	for (int index = 0; index < fishAmount; index++)
	{

		anema[index].setPosition(sf::Vector2f(anema[index].getPosition().x + 1, anema[index].getPosition().y));



		// Things to do before the ed fothe screen
		if (anema[index].getPosition().x > 0 && anema[index].getPosition().x < 1280) {

		}


		if (anema[index].getPosition().x >= 1280)
		{
			// make sure doesnt go below sand bar
			anema[index].setPosition(sf::Vector2f(-1000 - (rand() % static_cast<int>(-800) - 400), (rand() % static_cast<int>(720)) + 200));
		
			checkLegalState(anema[index], waterLevel);
		}
	}
}

void Animal::clickDetection(sf::Vector2f mouse)
{
}

void Animal::checkLegalState(sf::CircleShape &anema, int waterLevel)
{
	// make sure they dont go above sea level o underground
	// TODO
	if (anema.getPosition().y <= waterLevel)
	{
		anema.setPosition(sf::Vector2f(anema.getPosition().x, waterLevel + OFFSET));
	}
	if (anema.getPosition().x <= 0)
	{
		anema.setPosition(sf::Vector2f(OFFSET, anema.getPosition().y));
	}
	if (anema.getPosition().x >= 1280)
	{
		anema.setPosition(sf::Vector2f(1280 - OFFSET, anema.getPosition().x));
	}
	if (anema.getPosition().y >= 690)
	{
		anema.setPosition(sf::Vector2f(anema.getPosition().x, 690 - OFFSET));
	}
}
