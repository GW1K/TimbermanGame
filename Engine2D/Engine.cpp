#include "Engine.h"
#include <iostream>
#include "Player.h"
#include "Background.h"
#include "MainMenuState.h"

Engine::Engine():
	pLogger("../Logger.txt"), dt(1.0f / 60.0f)
{
	pEngineData.window = new GameMainWindow();
	pEngineData.stateMachine.addState((State*)new MainMenuState(pEngineData));
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
		this->pEngineData.stateMachine.getCurrentState().draw(interpolation);
	}
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