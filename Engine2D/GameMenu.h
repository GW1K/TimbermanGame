#pragma once
#include <SFML/Graphics.hpp>

class GameMenu
{
private:
	sf::RenderWindow *window;
	sf::RectangleShape bg;
	sf::RectangleShape btnPlay;
	sf::RectangleShape btnExit;
	sf::Font font;
	sf::Text text[2];

public:
	GameMenu() {};
	GameMenu(sf::RenderWindow* window);
	~GameMenu();
	void draw();
	void MoveUp();
	void MoveDown();
	int selectedIndex;
};

