#include <iostream>
#include "fmodgms.hpp"

#define GM_TRUE 1.0f
#define GM_FALSE 0.0f

double FMODGMS::Sys_Create()
{
	result = FMOD::System_Create(&system);      // Create the main system object.
	Util_ErrorChecker();

	std::cout << "FMOD System created" << std::endl;
	return GM_TRUE;
}

double FMODGMS::Sys_Init()
{
	result = system->init(512, FMOD_INIT_NORMAL, 0);    // Initialize FMOD.
	Util_ErrorChecker();

	std::cout << "FMOD System initialized" << std::endl;
	return GM_TRUE;
}

double FMODGMS::Sys_Close()
{
	result = system->release();
	Util_ErrorChecker();

	std::cout << "FMOD System closed" << std::endl;
	return GM_TRUE;
}

double FMODGMS::Snd_Load(char* filename)
{
	result = system->createSound(filename, FMOD_DEFAULT, 0, &sound);

	if (Util_ErrorChecker() == GM_TRUE)
	{
		return 0;
	}

	else
		return -1;
}

double FMODGMS::Snd_Play(double soundIndex, double channelIndex)
{
	int i = (int)round(soundIndex);
	int c = (int)round(channelIndex);

	result = system->playSound(sound, 0, false, &channel);

	return Util_ErrorChecker();
}

double FMODGMS::Util_ErrorChecker()
{
	if (result != FMOD_OK)
	{
		std::cout << "FMOD error! (" << result << ") " << FMOD_ErrorString(result) << std::endl;
		return GM_FALSE;
	}

	return GM_TRUE;
}