#pragma once
#include <SFML/Graphics.hpp>
class GameMenu
{
private:

	
	sf::RectangleShape bg;
	sf::RectangleShape btnPlay;
	sf::RectangleShape btnExit;
	sf::Font font;
	sf::Text text[2];
	sf::RenderWindow* window;
	
	
	


public:

	GameMenu() {};
	GameMenu(sf::RenderWindow* window);
	~GameMenu();
	void draw();
	void MoveUp();
	void MoveDown();
	int selectedIndex;
	

};

