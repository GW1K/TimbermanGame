#include "Cloud.h"
#include <iostream>

Cloud::Cloud(sf::RenderWindow* window) :LoadObject("./Assets/objects/cloud.png")
{
	this->window = window;
	this->isActive = false;
	objectTxt.loadFromFile(path);
	objectSprite.setTexture(objectTxt);
	objectSprite.scale(0.4, 0.4);
	objectSprite.setPosition(0, 0);
}

void Cloud::draw() {
	window->draw(objectSprite);
}

void Cloud::update(float dt) {


	if (!isActive)
	{
		speed = 400;
		srand((int)time(NULL) * 10);
		float newPosy = ((rand() % 300) + 50);
		objectSprite.setPosition(-50, newPosy);
		isActive = true;
		
	}
	else
	{
		
		float newPosx = objectSprite.getPosition().x + (speed * dt/2000);
		
		objectSprite.setPosition(newPosx, objectSprite.getPosition().y);
		if (objectSprite.getPosition().x > window->getSize().x)
		{
			isActive = false;
		}
	}


	

}
