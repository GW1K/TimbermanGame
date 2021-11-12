#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Background.h"
#include "GameMenu.h"

enum class GameScreens{ MENU_SCREEN, GAME_SCREEN };

class Engine
{
private:
	Engine();
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

	sf::RenderWindow *window;
	sf::Event sfEvent;
	GameMenu* startMenu;
	GameScreens gameScreen;

	//Settings
	std::string title;
	sf::VideoMode resolution;
	bool fullscreen;
	bool vSync;
	unsigned frameRateLimit;

	//Clock
	sf::Clock clock;
	sf::Time gameTime;

	//Functions
	void initVideoSettings();
	void initWindow();
};

