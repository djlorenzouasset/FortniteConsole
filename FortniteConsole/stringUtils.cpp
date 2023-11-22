#include "headers/stringUtils.hpp"

std::vector<std::string> split(const std::string& str, const std::string& delim)
{
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

dye::R<std::string> colorString(std::string& str, const LogType& logType)
{
    switch (logType)
    {
    case LogType::Default:
        return dye::green(str);
    case LogType::LogGameFeatures:
        return dye::purple(str);
    case LogType::LogInit:
        return dye::aqua(str);
    case LogType::LogOnline:
        return dye::blue(str);
    case LogType::LogFort:
        return dye::light_aqua(str);
    case LogType::LogHotfixManager:
        return dye::grey(str);
    case LogType::LogFortInstallBundleManager:
        return dye::yellow(str);
    default:
        return dye::white(str);
    }
}

int escapeCharacter(std::string& str)
{
    char target = ']';
    int count = 0;
    int index = -1;

    for (int i = 0; i < str.length(); i++) {
        if (str.at(i) == target) {
            count++;
            if (count == 2) {
                index = i;
                break;
            }
        }
    }
    return index;
}