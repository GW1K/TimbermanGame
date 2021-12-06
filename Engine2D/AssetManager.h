#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include "Logger.h"

class AssetManager
{
public:
	AssetManager():logger("../Logger.txt") { }
	~AssetManager() { }

	void loadTexture(std::string name, std::string fileName);
	sf::Texture& getTexture(std::string name);

	void loadFont(std::string name, std::string fileName);
	sf::Font& getFont(std::string name);

	void loadSound(std::string name, std::string fileName, sf::SoundBuffer& soundBuffer);
	sf::Sound& getSound(std::string name);

private:
	Logger logger;
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, sf::Sound> sounds;
};
