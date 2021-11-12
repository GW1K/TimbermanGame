#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameMenu.h"

class GameMenu;

enum class GameScreens { MENU_SCREEN, GAME_SCREEN };

class GameMainWindow : public sf::RenderWindow
{
public:
	GameMainWindow();
	virtual ~GameMainWindow();

	GameMenu* getStartMenu();

	GameScreens getCurrentScreen();
	void setCurrentScreen(GameScreens screen);

private:
	GameMenu* startMenu;
	GameScreens currentScreen;

	//Main window settings
	std::string title;
	sf::VideoMode resolution;
	bool fullscreen;
	bool vSync;
	unsigned frameRateLimit;

	void initVideoSettings();
};

