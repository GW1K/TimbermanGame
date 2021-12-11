#include "Log.h"

Log::Log(sf::RenderWindow* window) :LoadObject("./Assets/objects/log.png"), pLogger("../Logger.txt")
{
	this->window = window;
	this->logSpeedX = 1000;
	this->logSpeedY = 2000;
	this->logActive = false;
	objectTxt.loadFromFile(path);
	objectSprite.setTexture(objectTxt);
	objectSprite.setPosition(sf::Vector2f(this->window->getSize().x / 2 - 75, this->window->getSize().y / 2 + 150));
	objectSprite.setScale(sf::Vector2f(0.4, 0.35));
	pLogger.log("Loaded Log texture: " + path);
}

void Log::setRight()
{
	objectSprite.setPosition(sf::Vector2f(this->window->getSize().x / 2 - 75, this->window->getSize().y / 2 + 150));
	logSpeedX = -1500;
	logActive = true;
}
void Log::setLeft()
{
	objectSprite.setPosition(sf::Vector2f(this->window->getSize().x / 2 - 75, this->window->getSize().y / 2 + 150));
	logSpeedX = 1500;
	logActive = true;
}

void Log::update(float timedelta)
{
	if (logActive)
	{
		float newPositionX = objectSprite.getPosition().x + (logSpeedX * timedelta);
		float newPositionY = objectSprite.getPosition().y + (logSpeedY * timedelta);
		objectSprite.setPosition(newPositionX, newPositionY);

		if (objectSprite.getPosition().x < 200 || objectSprite.getPosition().x > 1500)
		{
			logActive = false;
			objectSprite.setPosition(sf::Vector2f(this->window->getSize().x / 2 - 75, this->window->getSize().y / 2 + 150));
		}
	}

}

void Log::draw()
{
	window->draw(objectSprite);
}
