#pragma once
#include "LoadObject.h"
class Log : public LoadObject
{
private:
	sf::RenderWindow* window;
	float logSpeedX;
	float logSpeedY;
	bool logActive;
	Logger pLogger;
public:
	Log(sf::RenderWindow* window);
	void setRight();
	void setLeft();
	void update(float timedelta);
	void draw();
};