#include "ColorScheme.h"

sf::Color ColorScheme::getLightBlue()
{
	return sf::Color(140, 165, 255, 255);
}

sf::Color ColorScheme::getInterimBlue()
{
	return sf::Color(25, 125, 225, 255);
}

sf::Color ColorScheme::getVoidBlue()
{
	return sf::Color(0, 0, 200, 255);
}

sf::Color ColorScheme::getRetroGray()
{
	return sf::Color(150, 150, 150, 255);
}

sf::Color ColorScheme::getMidGray()
{
	return sf::Color(88, 88, 88, 255);
}

sf::Color ColorScheme::getMidWhite()
{
	return sf::Color(207, 207, 207, 255);
}

sf::Color ColorScheme::bubbleColor()
{
	return sf::Color(25, 125, 225, 130);
}

sf::Color ColorScheme::bodyOfWaterColor()
{
	return sf::Color(25, 125, 225, 155);
}

sf::Color ColorScheme::sandColor()
{
	return sf::Color(255, 255, 135, 255);
}

sf::Color ColorScheme::sands(int color)
{
	switch (color) {
	case 1: return sf::Color(255, 185, 135, 255); break;
	case 2: return sf::Color(190, 190, 80, 255); break;
	case 3: return sf::Color(215, 215, 100, 255); break;
	default: return sf::Color(225, 225, 135, 255); break;
	}
}
