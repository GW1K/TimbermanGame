#include "Background.h"

Background::Background(sf::RenderWindow* window, std::string path) :LoadObject(path)
{
	this->window = window;
	objectTxt.loadFromFile(path);
	objectSprite.setTexture(objectTxt);
	objectSprite.setPosition(0, 0);
	objectSprite.setScale(sf::Vector2f(0.9, 0.9));
}

void Background::draw()
{
	this->window->draw(objectSprite);
}