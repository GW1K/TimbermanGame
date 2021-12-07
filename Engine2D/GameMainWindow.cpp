#include "GameMainWindow.h"

GameMainWindow::GameMainWindow()
{
	this->initVideoSettings();
	this->create(
		this->resolution,
		this->title,
		this->fullscreen ?
		sf::Style::Fullscreen :
		sf::Style::Titlebar | sf::Style::Close
	);
}

GameMainWindow::~GameMainWindow()
{

}

void GameMainWindow::initVideoSettings()
{
	this->title = "Timberman";
	this->fullscreen = false;
	this->vSync = false;
	this->resolution.width = 1920;
	this->resolution.height = 1080;
	this->frameRateLimit = 60;
}

unsigned GameMainWindow::getFrameRateLimit()
{
	return this->frameRateLimit;
}
