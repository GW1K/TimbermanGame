#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class GameMainWindow : public sf::RenderWindow
{
public:
	GameMainWindow();
	virtual ~GameMainWindow();

	unsigned getFrameRateLimit();

private:

	//Main window settings
	std::string title;
	sf::VideoMode resolution;
	bool fullscreen;
	bool vSync;
	unsigned frameRateLimit;

	void initVideoSettings();
};

