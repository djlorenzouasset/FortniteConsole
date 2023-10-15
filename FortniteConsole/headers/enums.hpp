#pragma once
#include <iostream>

enum LogType : uint8_t
{
	Default = 0, // used for useless logs
	LogInit = 1,
	LogFort = 2,
	LogOnline = 3,
	LogGameFeatures = 4,
	LogHotfixManager = 5,
	LogFortInstallBundleManager = 6
};