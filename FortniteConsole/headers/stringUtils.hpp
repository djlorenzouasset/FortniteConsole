#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include "enums.hpp"
#include "color.hpp"

// split text in the string
std::vector<std::string> split(const std::string& str, const std::string& delim);

// format a string to a colored log
dye::R<std::string> colorString(std::string& str, const LogType& logType);

// remove the datetime from the log string
int escapeCharacter(std::string& str);
