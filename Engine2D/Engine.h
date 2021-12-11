#pragma once
#include <SFML/Graphics.hpp>
#include "GameMainWindow.h"
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "Logger.h"

/**
 * \brief Typ struktury zawierajacy podstawowe dane silnika
 *
 */
typedef struct EngineData {
	GameMainWindow* window;
	sf::SoundBuffer soundBuffer;
	StateMachine stateMachine;
	AssetManager assetManager;
	InputManager inputManager;
	bool input;
} EngineData;

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

protected:
	void handleEvent();

	Logger pLogger;
	EngineData pEngineData;
	sf::Event pEvent;

private:
	sf::Clock mClock;
	float dt;
};

