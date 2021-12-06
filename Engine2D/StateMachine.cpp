/*****************************************************************//**
 * \file   StateMachine.cpp
 * \brief  Plik zrodlowy klasy pozwalajacej na dodawnie stanow gry i przechodzenie pomiedzy nimi
 *
 *
 * \author Michal Mosiolek Bartosz Mozdzierz Wiktor Gozdek
 * \date   November 2021
 *********************************************************************/
#include "StateMachine.h"

/**
 * \brief Metoda pozwala na dodanie stanu gry
 * \param newState Stan ktory ma zostac dodany
 * \param isReplacing Flaga pozwalajaca na podmienienie aktualnego stanu gry nowym
 */
void StateMachine::addState(State* newState, bool isReplacing)
{
	this->isAdding = true;
	this->isReplacing = isReplacing;
	this->newState = newState;
}

/**
 * \brief Metoda pozwala na usuniecie stanu gry
 * 
 */
void StateMachine::removeState()
{
	this->isRemoving = true;
}

/**
 * \brief Metoda przetwarzajaca zmiany stanu gry
 *
 */
void StateMachine::processStateChanges()
{
	if (this->isRemoving && !this->states.empty())
	{
		this->states.pop();

		if (!this->states.empty())
		{
			this->states.top()->resume();
		}

		this->isRemoving = false;
	}

	if (this->isAdding)
	{
		if (!this->states.empty())
		{
			if (this->isReplacing)
			{
				this->states.pop();
			}
			else
			{
				this->states.top()->pause();
			}
		}

		this->states.push(std::move(this->newState));
		this->states.top()->init();
		this->isAdding = false;
	}
}

/**
 * \brief Metoda zwracajaca aktualny stan gry
 * \return Zwraca aktualny stan
 */
State& StateMachine::getCurrentState()
{
	return *this->states.top();
}
