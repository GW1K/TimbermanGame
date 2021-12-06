#include "Background.h"

Background::Background(sf::RenderWindow* window, std::string path) :LoadObject(path)
{
	this->window = window;
	objectTxt.loadFromFile(path);
	objectSprite.setTexture(objectTxt);
	objectSprite.setPosition(0, 0);
	sf::Vector2f targetSize(window->getSize().x, window->getSize().y);
	objectSprite.setScale(
		targetSize.x/objectSprite.getLocalBounds().width,
		targetSize.y/objectSprite.getLocalBounds().height
	);
}

void Background::draw()
{
	this->window->draw(objectSprite);
}