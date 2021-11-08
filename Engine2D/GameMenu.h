#pragma once
#include <SFML/Graphics.hpp>
class GameMenu
{
private:
	sf::RenderWindow* menuWindow;
	sf::RectangleShape bg;
	sf::RectangleShape btnPlay;
	sf::RectangleShape btnExit;

public:
	GameMenu(sf::RenderWindow* menuWindow);

};

