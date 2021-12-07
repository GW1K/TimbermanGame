#pragma once
#include "LoadObject.h"
class Log : public LoadObject
{
private:
	sf::RenderWindow* window;
	float logSpeedX;
	float logSpeedY;
	bool logActive;
public:
	Log(sf::RenderWindow* window);
	void setRight();
	void setLeft();
	void update(float timedelta);
	void draw();
};