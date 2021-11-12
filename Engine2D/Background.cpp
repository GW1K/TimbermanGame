#include "Background.h"

Background::Background(sf::RenderWindow* window)
{
	this->window = window;
	//Tymczasowo kiedyœ bedzie ³adowanie teksutr 
	bg.setPosition(0, 0);
	bg.setSize(sf::Vector2f(window->getSize().x,window->getSize().y));
	bg.setFillColor(sf::Color(70, 70, 70));
}

void Background::draw()
{
	this->window->draw(bg);
}