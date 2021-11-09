#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Background.h"
#include "GameMenu.h"

enum class GameScreens{ MENU_SCREEN, GAME_SCREEN };

class Engine
{
public:
	Engine();
	~Engine();
	void run();

private:
	sf::RenderWindow *window;
	sf::Event sfEvent;
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

