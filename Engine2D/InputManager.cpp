/*****************************************************************//**
 * \file   InputManager.cpp
 * \brief  Plik zrodlowy menadzera wejscia
 *
 *
 * \author Michal Mosiolek Bartosz Mozdzierz Wiktor Gozdek
 * \date   November 2021
 *********************************************************************/
#include "InputManager.h"

/**
 * \brief Metoda zwraca informacje o tym czy obiekt gry zostal klikniety
 * \param sprite Obiekt ktory ma zostac sprawdzony
 * \param button Przycisk ktorym kliknieto obiekt
 * \param window Okno glowne zawierajace obiekt
 * \return Zwraca true jesli obiekt zostal klikniety lub false w przeciwnym przypadku 
 */
bool InputManager::isSpriteClicked(sf::Sprite& sprite, sf::Mouse::Button& button, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		sf::IntRect spriteRect(sprite.getPosition().x, sprite.getPosition().y,
			sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
		if (spriteRect.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}
	return false;
}

/**
 * \brief Metoda sluzaca do pobrania pozycji kursora
 * \param window Okno dla ktorego maja zostac pobrane wspolrzedne kursora
 * \return Zwraca pozycje kursora
 */
sf::Vector2i InputManager::getMousePosition(sf::RenderWindow& window)
{
	return sf::Mouse::getPosition(window);
}
