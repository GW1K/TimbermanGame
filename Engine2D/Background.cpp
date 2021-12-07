#include "Background.h"

Background::Background(sf::RenderWindow* window, std::string path) :LoadObject(path)
{
	this->window = window;
	objectTxt.loadFromFile(path);
	objectSprite.setTexture(objectTxt);
	objectSprite.setPosition(0, 0);
}

void Background::draw()
{
	this->window->draw(objectSprite);
}