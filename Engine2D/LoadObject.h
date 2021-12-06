#pragma once
#include <SFML/Graphics.hpp>
class LoadObject
{
protected:
	sf::Texture objectTxt;
	sf::Sprite objectSprite;
	std::string path;
public:
	LoadObject();
	LoadObject(std::string path);
	virtual void draw() = 0;
};

