#include "MainMenuState.h"
#include "GameState.h"
#include <iostream>

MainMenuState::MainMenuState(EngineData& engineData):
	mEngineData(engineData), mLogger("../Logger.txt")
{
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::init()
{
	this->mEngineData.assetManager.loadFont("mainMenuFont", "./Assets/fonts/font.ttf");
	this->mEngineData.assetManager.loadTexture("mainMenuBackground", "./Assets/background/menubg.png");
	this->mEngineData.assetManager.loadTexture("mainMenuButton", "./Assets/menu/btn.png");
	this->mEngineData.assetManager.loadTexture("mainMenuButtonFoc", "./Assets/menu/btn_focus.png");
	this->mEngineData.assetManager.loadTexture("mainMenuButtonSel", "./Assets/menu/btn_sel.png");
	this->mEngineData.assetManager.loadSound("mainMenuButtonClick", "./Assets/sounds/menu_click.ogg", this->mEngineData.soundBuffer);
	
	this->mEngineData.assetManager.getSound("mainMenuButtonClick").setVolume(30.0f);

	this->background.setTexture(this->mEngineData.assetManager.getTexture("mainMenuBackground"));
	this->background.setPosition(0 ,0);
	this->background.setScale(
		this->mEngineData.window->getSize().x / this->background.getLocalBounds().width,
		this->mEngineData.window->getSize().y / this->background.getLocalBounds().height
	);

	this->background.setTexture(this->mEngineData.assetManager.getTexture("mainMenuBackground"));
	this->background.setPosition(0, 0);
	this->background.setScale(
		this->mEngineData.window->getSize().x / this->background.getLocalBounds().width,
		this->mEngineData.window->getSize().y / this->background.getLocalBounds().height
	);

	float buttonsMargin = mEngineData.window->getSize().y / 16.0f;

	this->buttons[0].setTexture(this->mEngineData.assetManager.getTexture("mainMenuButton"));
	this->buttons[0].setScale(sf::Vector2f(2.5f, 2.5f));
	this->buttons[0].setPosition(sf::Vector2f(
		mEngineData.window->getSize().x / 2.0f - this->buttons[0].getLocalBounds().width * 2.5f / 2.0f,
		mEngineData.window->getSize().y / 2.0f - this->buttons[0].getLocalBounds().height * 2.5f / 2.0f - buttonsMargin
	));
	
	this->buttons[1].setTexture(this->mEngineData.assetManager.getTexture("mainMenuButton"));
	this->buttons[1].setScale(sf::Vector2f(2.5f, 2.5f));
	this->buttons[1].setPosition(sf::Vector2f(
		mEngineData.window->getSize().x / 2.0f - this->buttons[1].getLocalBounds().width * 2.5f / 2.0f,
		mEngineData.window->getSize().y / 2.0f - this->buttons[1].getLocalBounds().height * 2.5f / 2.0f + buttonsMargin
	));

	this->buttonsText[0].setFont(this->mEngineData.assetManager.getFont("mainMenuFont"));
	this->buttonsText[0].setString("Play");
	this->buttonsText[0].setCharacterSize(30);
	this->buttonsText[0].setPosition(sf::Vector2f(
		mEngineData.window->getSize().x / 2.0f - this->buttonsText[0].getLocalBounds().width / 2.0f,
		mEngineData.window->getSize().y / 2.0f - this->buttonsText[0].getLocalBounds().height / 2.0f - buttonsMargin - 5.0f
	));

	this->buttonsText[1].setFont(this->mEngineData.assetManager.getFont("mainMenuFont"));
	this->buttonsText[1].setString("Exit");
	this->buttonsText[1].setCharacterSize(30);
	this->buttonsText[1].setPosition(sf::Vector2f(
		mEngineData.window->getSize().x / 2.0f - this->buttonsText[1].getLocalBounds().width / 2.0f,
		mEngineData.window->getSize().y / 2.0f - this->buttonsText[1].getLocalBounds().height / 2.0f + buttonsMargin - 5.0f
	));
	this->selectedIndex = 0;
}

void MainMenuState::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		this->moveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		this->moveDown();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
	{
		this->mEngineData.assetManager.getSound("mainMenuButtonClick").play();
		if (this->selectedIndex == 0)
		{
			this->mEngineData.stateMachine.addState((State*) new GameState(mEngineData), false);
		}
		if (this->selectedIndex == 1)
		{
			sf::sleep(sf::milliseconds(100));
			this->mEngineData.window->close();
		}
	}
}

void MainMenuState::update(float dt)
{
	for (int i = 0; i < 2; i++)
	{
		this->buttons[i].setTexture(this->mEngineData.assetManager.getTexture("mainMenuButton"));
		this->buttonsText[i].setFillColor(sf::Color::White);
	}
	this->buttons[selectedIndex].setTexture(this->mEngineData.assetManager.getTexture("mainMenuButtonFoc"));
	this->buttonsText[selectedIndex].setFillColor(sf::Color::Yellow);
}

void MainMenuState::draw(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
	{
		this->buttons[selectedIndex].setTexture(this->mEngineData.assetManager.getTexture("mainMenuButtonSel"));
	}
	this->mEngineData.window->draw(this->background);
	for (int i = 0; i < 2; i++)
	{
		this->mEngineData.window->draw(this->buttons[i]);
		this->mEngineData.window->draw(this->buttonsText[i]);
	}
}

void MainMenuState::moveUp()
{
	if (selectedIndex - 1 >= 0)
	{
		selectedIndex--;
	}
}

void MainMenuState::moveDown()
{
	if (selectedIndex + 1 < 2)
	{
		selectedIndex++;
	}
}
