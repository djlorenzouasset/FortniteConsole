#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "headers/stringUtils.hpp"

int parseLogs(std::string logPath)
{
	std::string currentLine;
	std::ifstream file(logPath);
	int pos, lenght = 0;

	if (!file)
	{
		std::cout << "[" << dye::red("ERROR") << "] The FortniteGame.log file doesn't exist. Open the game before the program and try again." << std::endl;
		return 0;
	}

	while (true)
	{
		if (!file.is_open())
			file.open(logPath);

		pos = lenght;
		file.seekg(0, file.end);
		lenght = file.tellg();
		file.seekg(pos, file.beg);

		while (file)
		{
			std::getline(file, currentLine);
			if (currentLine == "") continue;

			int lastChar = escapeCharacter(currentLine);
			if (lastChar != std::string::npos)
			{
				currentLine.erase(0, lastChar + 1);
			}

			auto level = split(currentLine, ":");
			// check if the level is available
			if (level.empty())
			{
				std::cout << currentLine << std::endl;
				continue;
			}

			std::string logLevel = level.at(0);
			std::string message = currentLine.substr(logLevel.length(), currentLine.length());

			if (logLevel.starts_with("LogInit")) std::cout << colorString(logLevel, LogType::LogInit) << message << std::endl;
			else if (logLevel.starts_with("LogFort")) std::cout << colorString(logLevel, LogType::LogFort) << message << std::endl;
			else if (logLevel.starts_with("LogOnline")) std::cout << colorString(logLevel, LogType::LogOnline) << message << std::endl;
			else if (logLevel.starts_with("LogGameFeatures")) std::cout << colorString(logLevel, LogType::LogGameFeatures) << message << std::endl;
			else if (logLevel.starts_with("LogHotfixManager")) std::cout << colorString(logLevel, LogType::LogHotfixManager) << message << std::endl;
			else if (logLevel.starts_with("LogFortInstallBundleManager")) std::cout << colorString(logLevel, LogType::LogFortInstallBundleManager) << message << std::endl;
			else std::cout << colorString(logLevel, LogType::Default) << message << std::endl;
		}
		// close the file for reopen it updated
		file.close();
		Sleep(5);
	}
	return 0;
}

int main()
{
	SetConsoleTitleW(L"Fortnite");
	// get the log of fortnite in the %appdata% folder
	std::string path = getenv("localappdata");
	path.append(R"(\FortniteGame\Saved\Logs\FortniteGame.log)");

	parseLogs(path);
	std::system("pause");
}
