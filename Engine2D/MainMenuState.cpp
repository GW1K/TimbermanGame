#include "MainMenuState.h"
#include "GameState.h"

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

	this->background.setTexture(this->mEngineData.assetManager.getTexture("mainMenuBackground"));
	this->background.setPosition(0 ,0);
	this->background.setScale(
		this->mEngineData.window->getSize().x / this->background.getLocalBounds().width,
		this->mEngineData.window->getSize().y / this->background.getLocalBounds().height
	);

	this->text[0].setFont(this->mEngineData.assetManager.getFont("mainMenuFont"));
	this->text[0].setString("Play");
	this->text[0].setCharacterSize(28);
	this->text[0].setFillColor(sf::Color::Green);
	this->text[0].setPosition(sf::Vector2f(
		(mEngineData.window->getSize().x / 2) - this->text[0].getPosition().x,
		(mEngineData.window->getSize().y / 2) - this->text[0].getPosition().y - 50
	));

	this->text[1].setFont(this->mEngineData.assetManager.getFont("mainMenuFont"));
	this->text[1].setString("Exit");
	this->text[1].setCharacterSize(28);
	this->text[1].setFillColor(sf::Color::White);
	this->text[1].setPosition(sf::Vector2f(
		(mEngineData.window->getSize().x / 2) - this->text[1].getPosition().x,
		(mEngineData.window->getSize().y / 2) - this->text[1].getPosition().y + 50
	));
	this->selectedIndex = 1;
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
		if (this->selectedIndex == 1)
		{
			this->mEngineData.stateMachine.addState((State*) new GameState(mEngineData), false);
		}
		if (this->selectedIndex == 0)
		{
			this->mEngineData.window->close();
		}
	}
}

void MainMenuState::update(float dt)
{
}

void MainMenuState::draw(float dt)
{
	this->mEngineData.window->clear();

	this->mEngineData.window->draw(this->background);
	for (int i = 0; i < 2; i++)
	{
		this->mEngineData.window->draw(this->text[i]);
	}
	
	this->mEngineData.window->display();
}

void MainMenuState::moveUp()
{
	if (selectedIndex + 1 < 2)
	{
		this->text[selectedIndex].setFillColor(sf::Color::Green);
		selectedIndex++;
		this->text[selectedIndex].setFillColor(sf::Color::White);
	}
}

void MainMenuState::moveDown()
{
	if (selectedIndex - 1 >= 0)
	{
		this->text[selectedIndex].setFillColor(sf::Color::Green);
		selectedIndex--;
		this->text[selectedIndex].setFillColor(sf::Color::White);
	}
}
