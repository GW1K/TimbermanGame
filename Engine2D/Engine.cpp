#include "Engine.h"
#include <iostream>
#include "Player.h"
#include "Background.h"
#include "MainMenuState.h"

Engine::Engine():
	pLogger("../Logger.txt"), dt(1.0f / 60.0f), showAxis(true)
{
	pEngineData.window = new GameMainWindow();
	pEngineData.stateMachine.addState((State*)new MainMenuState(pEngineData));

	if (this->showAxis)
	{
		this->axisLines[0][0].position = sf::Vector2f(0.0f, pEngineData.window->getSize().y / 2.0f);
		this->axisLines[0][1].position = sf::Vector2f((float)pEngineData.window->getSize().x, pEngineData.window->getSize().y / 2.0f);
		this->axisLines[1][0].position = sf::Vector2f(pEngineData.window->getSize().x / 2.0f, 0.0f);
		this->axisLines[1][1].position = sf::Vector2f(pEngineData.window->getSize().x / 2.0f, (float)pEngineData.window->getSize().y);
	}
}

Engine::~Engine()
{
	delete pEngineData.window;
}

void Engine::run()
{
	pLogger.log("Engine is running ...");
	
	float newTime, frameTime, interpolation;

	float currentTime = this->mClock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;
	this->dt = 1.0f / this->pEngineData.window->getFrameRateLimit();
	
	while (pEngineData.window->isOpen())
	{
		this->pEngineData.stateMachine.processStateChanges();

		newTime = this->mClock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;
		if (frameTime >= 0.25f)
		{
			frameTime = 0.25f;
		}
		currentTime = newTime;
		accumulator += frameTime;
		while (accumulator >= dt)
		{
			handleEvent();
			this->pEngineData.stateMachine.getCurrentState().handleInput();
			this->pEngineData.stateMachine.getCurrentState().update(dt);

			accumulator -= dt;
		}
		interpolation = accumulator / dt;
		this->pEngineData.window->clear();
		this->pEngineData.stateMachine.getCurrentState().draw(interpolation);
		if (this->showAxis) this->drawAxis();
		this->pEngineData.window->display();
	}
}

void Engine::drawAxis()
{
	this->pEngineData.window->draw(this->axisLines[0], 2, sf::Lines);
	this->pEngineData.window->draw(this->axisLines[1], 2, sf::Lines);
}

/**
 * \brief Metoda obslugujaca eventy
 *
 */
void Engine::handleEvent()
{
	while (pEngineData.window->pollEvent(this->pEvent))
	{
		switch (pEvent.type)
		{
		case sf::Event::KeyReleased:
			this->pEngineData.input = true;
			break;
		case sf::Event::Closed:
			pEngineData.window->close();
			pLogger.log("Application closed");
			break;
		case sf::Event::Resized:
			pLogger.log("Width: %d Height: %d", pEvent.size.width, pEvent.size.height);
			break;
		}
	}
}