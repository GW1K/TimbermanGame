#pragma once
#include <SFML/Graphics.hpp>
class Engine
{
public:
	Engine();
	~Engine();
	void run();

private:
	sf::RenderWindow* window;
	sf::Event sfEvent;

	//Settings
	std::string title;
	sf::VideoMode resolution;
	bool fullscreen;
	bool vSync;
	unsigned frameRateLimit;

	//Clock

	//Functions
	void initVideoSettings();
	void initWindow();
	void initKeys();
};

