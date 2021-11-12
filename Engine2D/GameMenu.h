#pragma once
#include <SFML/Graphics.hpp>
#include "GameMainWindow.h"

class GameMainWindow;

class GameMenu
{
private:
	GameMenu();

	GameMainWindow* window;
	sf::RectangleShape bg;
	sf::RectangleShape btnPlay;
	sf::RectangleShape btnExit;
	sf::Font font;
	sf::Text text[2];
	int selectedIndex;

public:
	GameMenu(GameMainWindow* window);
	~GameMenu();
	void draw();
	void moveUp();
	void moveDown();
	int getSelectedIndex();
};

