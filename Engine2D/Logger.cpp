#include "Logger.h"
/*****************************************************************//**
 * \file   Logger.cpp
 * \brief Plik zrodlowy dla loggera 
 * 
 * 
 * \author Michal Mosiolek Bartosz Mozdzierz Wiktor Gozdek
 * \date   November 2021
 *********************************************************************/
#include <ctime>
#include <cstdarg>

/**
 * 
 * \brief Konstruktor loggera
 * \param fileName nazwa pliku
 */
Logger::Logger(std::string fileName)
{
	pStream.open(fileName, std::ios::app);
	if (pStream.fail()) 
	{
		std::cout << getCurrentTime() << ": Cannot open default logger file" << std::endl;
	}
}

/**
 * \brief Destruktor zamykajacy plik
 * 
 */
Logger::~Logger()
{
	pStream.close();
}

/**
 * .
 * \brief Metoda zwracajaca biezacy czas
 * \return Zwraca biezacy czas 
 */
const std::string Logger::getCurrentTime()
{
	char timeBuffer[50];
	time_t now = time(0);
	ctime_s(timeBuffer, sizeof(timeBuffer), &now);
	timeBuffer[strlen(timeBuffer) - 1] = '\0';
	return timeBuffer;
}

/**
 * .
 * \brief Metoda pozwalajaca na zapisanie wiadomosci do loggera
 * \param message Wiadomosc do loggera
 */
void Logger::log(std::string message)
{
	pStream << getCurrentTime() << ": " << message << std::endl;
}

/**
 * .
 * \brief Metoda pozwala na logowanie do pliku podobnie do funkcji fprintf
 * \param format  Format wiadomosci
 */
void Logger::log(char const* const format,...)
{
	char message[BUFSIZ];
	va_list args;
	va_start(args, format);
	vsprintf_s(message, sizeof(message), format, args);
	va_end(args);
	this->log(std::string(message));
}
