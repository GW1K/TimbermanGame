/*****************************************************************//**
 * \file   AssetManager.cpp
 * \brief  Plik zrodlowy menadzera zasobow
 *
 *
 * \author Michal Mosiolek Bartosz Mozdzierz Wiktor Gozdek
 * \date   November 2021
 *********************************************************************/
#include "AssetManager.h"

/**
 * \brief Metoda sluzaca do zaladowania tekstury
 * \param name Nazwa tekstury
 * \param fileName Sciezka do pliku z tekstura
 */
void AssetManager::loadTexture(std::string name, std::string fileName)
{
	sf::Texture texture;
	if (texture.loadFromFile(fileName))
	{
		this->textures[name] = texture;
		logger.log("Loaded texture - %s", fileName.c_str());
		return;
	}
	logger.log("Cannot load texture - %s", fileName.c_str());
}

/**
 * \brief Metoda sluzaca do pobrania tekstury po nazwie
 * \param name Nazwa tekstury
 * \return Zwraca teksture
 */
sf::Texture& AssetManager::getTexture(std::string name)
{
	return this->textures.at(name);
}

/**
 * \brief Metoda sluzaca do zaladowania czcionki
 * \param name Nazwa czcionki
 * \param fileName Sciezka do pliku z czcionka
 */
void AssetManager::loadFont(std::string name, std::string fileName)
{
	sf::Font font;
	if (font.loadFromFile(fileName))
	{
		this->fonts[name] = font;
		logger.log("Loaded font - %s", fileName.c_str());
		return;
	}
	logger.log("Cannot load font - %s", fileName.c_str());
}

/**
 * \brief Metoda sluzaca do pobrania czcionki po nazwie
 * \param name Nazwa czcionki
 * \return Zwraca czcionke
 */
sf::Font& AssetManager::getFont(std::string name)
{
	return this->fonts.at(name);
}

/**
 * \brief Metoda sluzaca do zaladowania dzwieku
 * \param name Nazwa dzwieku
 * \param fileName Sciezka do pliku z dzwiekiem
 */
void AssetManager::loadSound(std::string name, std::string fileName, sf::SoundBuffer& soundBuffer)
{
	sf::Sound sound;
	if (soundBuffer.loadFromFile(fileName))
	{
		sound.setBuffer(soundBuffer);
		this->sounds[name] = sound;
		logger.log("Loaded sound - %s", fileName.c_str());
		return;
	}
	logger.log("Cannot load sound - %s", fileName.c_str());
}

/**
 * \brief Metoda sluzaca do pobrania dziweku po nazwie
 * \param name Nazwa dziweku
 * \return Zwraca dziwek
 */
sf::Sound& AssetManager::getSound(std::string name)
{
	return this->sounds.at(name);
}
