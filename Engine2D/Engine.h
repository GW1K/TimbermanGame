#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Background.h"
#include "GameMainWindow.h"

class Engine
{
private:
	Engine();
	~Engine();
	Engine(Engine const& copy);
	Engine& operator=(Engine const& copy);

public:
	static Engine& getInstance()
	{
		static Engine instance;
		return instance;
	}
	void run();

private:
	GameMainWindow* window;
	sf::Event sfEvent;

	//Engine main loop timers
	sf::Clock clock;
	sf::Time gameTime;
};

