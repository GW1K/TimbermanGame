#pragma once
#include <SFML/Graphics.hpp>

class GameMenu
{
private:
	GameMenu();

	sf::RenderWindow *window;
	sf::RectangleShape bg;
	sf::RectangleShape btnPlay;
	sf::RectangleShape btnExit;
	sf::Font font;
	sf::Text text[2];

public:
	GameMenu(sf::RenderWindow* window);
	~GameMenu();
	void draw();
	void MoveUp();
	void MoveDown();
	int selectedIndex;
};

