#include "Log.h"
#include <iostream>
Log::Log(sf::RenderWindow* window) :LoadObject("./Assets/objects/log.png")
{
	this->window = window;
	this->logSpeedX = 1000;
	this->logSpeedY = -1500;
	this->logActive = false;
	objectTxt.loadFromFile(path);
	objectSprite.setTexture(objectTxt);
	objectSprite.setPosition(sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y / 2));
	objectSprite.setScale(sf::Vector2f(0.35, 0.35));
}
void Log::setRight()
{
	objectSprite.setPosition(sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y / 2));
	logSpeedX = -1500;
	logActive = true;
}
void Log::setLeft()
{
	objectSprite.setPosition(sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y / 2));
	logSpeedX = 1500;
	logActive = true;
}
void Log::draw()
{
	window->draw(objectSprite);
}
void Log::update(float timedelta)
{
	if (logActive)
	{
		float newPositionX = objectSprite.getPosition().x + (logSpeedX * timedelta/1000);
		float newPositionY = objectSprite.getPosition().y + (logSpeedY * timedelta/1000);
		objectSprite.setPosition(newPositionX, newPositionY);

		if (objectSprite.getPosition().x < -100 || objectSprite.getPosition().x > 2000)
		{
			logActive = false;
			objectSprite.setPosition(sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y / 2));
		}
	}
	
}