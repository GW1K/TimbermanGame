#include "Background.h"

Background::Background()
{
	//Tymczasowo kiedyœ bedzie ³adowanie teksutr 
	bg.setPosition(0, 0);
	bg.setSize(sf::Vector2f(1024,720));
	bg.setFillColor(sf::Color(70, 70, 70));
}

void Background::Draw(sf::RenderWindow& window)
{
	window.draw(bg);
}