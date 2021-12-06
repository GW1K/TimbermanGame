#pragma once
#include <string>
#include <fstream>
#include <iostream>

class Logger
{
public:
	Logger(std::string fileName);
	~Logger();
	virtual void log(std::string message);
	virtual void log(char const* const format, ...);

private:
	const std::string getCurrentTime();

	std::ofstream pStream;
};


