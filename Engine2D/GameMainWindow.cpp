#include "GameMainWindow.h"

GameMainWindow::GameMainWindow()
{
	this->initVideoSettings();
	this->currentScreen = GameScreens::MENU_SCREEN;
	if (this->fullscreen)
	{
		this->create(this->resolution, this->title, sf::Style::Fullscreen);
	}
	else
	{
		this->create(this->resolution, this->title,
			sf::Style::Titlebar | sf::Style::Close
		);
	}
	this->setFramerateLimit(this->frameRateLimit);
	this->startMenu = new GameMenu(this);
}

GameMainWindow::~GameMainWindow()
{

}

void GameMainWindow::initVideoSettings()
{
	this->title = "Timberman";
	this->fullscreen = false;
	this->vSync = false;
	this->frameRateLimit = 120;
	this->resolution.width = 1024;
	this->resolution.height = 720;
}

GameMenu* GameMainWindow::getStartMenu()
{
	return this->startMenu;
}

GameScreens GameMainWindow::getCurrentScreen()
{
	return this->currentScreen;
}

void GameMainWindow::setCurrentScreen(GameScreens screen)
{
	this->currentScreen = screen;
}
