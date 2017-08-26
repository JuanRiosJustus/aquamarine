#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include "Water.h"
#include "Bubbles.h"
#include "Animal.h"
#include "ColorScheme.h"
#include "Utility.h"

int main()
{

	// window dimensions
	sf::Vector2i screenDimensions(1280, 720);

	// Create a window
	sf::RenderWindow window;
	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2.0f) - 755.0f, (sf::VideoMode::getDesktopMode().height / 2.0f) - 390.0f);
	window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "charcoal", sf::Style::Close);
	window.setPosition(centerWindow);
	window.setFramerateLimit(60.0f);

	// the background
	sf::Sprite background;
	sf::Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("assets/retro.jpg"))
	{
		std::cout << "Error, no image found" << std::endl;
		background.setColor(ColorScheme::getMidGray());
	}
	else {
		background.setTexture(backgroundTexture);
	}
	

	// the time
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	// the player
	Water water;

	// the bubbles
	Bubbles bubbleSpawner;

	// the animal
	Animal animal;

	// the mouse
	sf::Vector2f mouse;

	/* MAIN WINDOW LOOP */
	while (window.isOpen())
	{

		sf::Event eventHandler;




		/* MAIN EVENT LOOP*/
		while (window.pollEvent(eventHandler))
		{
			switch (eventHandler.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (eventHandler.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
				break;
			}
		}

		if (true)
		{
			mouse.x = sf::Mouse::getPosition(window).x;
			mouse.y = sf::Mouse::getPosition(window).y;
		}

		/* MAIN CONTROL FUNCTIONALITY */
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			std::cout << "Going left with: " << sf::Keyboard::A << std::endl;
			char left = 'a';
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			std::cout << "Going right with: " << sf::Keyboard::D << std::endl;
			char right = 'd';
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			std::cout << "Going up with: " << sf::Keyboard::W << std::endl;
			char up = 'w';
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			std::cout << "Going down with: " << sf::Keyboard::S << std::endl;
			char down = 's';
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			std::cout << "Mouse left button pressed " << std::endl;
			bubbleSpawner.clickDetection(mouse);
		}
		// UTILITY
		if (sf::Keyboard::isKeyPressed)
		{
			//std::cout << "Current mouse location: " << sf::Mouse::getPosition(window).x << "," << sf::Mouse::getPosition(window).y << std::endl;
			std::cout << "The current hour: " << aTime->tm_hour << std::endl;
			water.setWaterLevel(Utility::respectiveWaterLevel(aTime->tm_hour));
			animal.innateBehavior(mouse, water.getWaterLevel());

		}
		//std::cout << "Current position: " << mainPlayer.latitude() << "," << mainPlayer.longitude() << std::endl;
		window.clear();

		window.draw(background);
		
		water.drawWater(window);
		bubbleSpawner.generateBubbles(window, water.getWaterLevel());
		animal.drawAnimal(window);

		window.display();

	}
	/* END OF MAIN WINDOW */

	return 0;
}