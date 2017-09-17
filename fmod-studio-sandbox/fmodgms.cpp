#include <iostream>
#include "./fmod_studio_api/fmod.hpp"
#include "./fmod_studio_api/fmod_errors.h"

#define GM_TRUE 1.0f
#define GM_FALSE 0.0f

class FMODGMS
{
public:
	FMOD_RESULT result;
	FMOD::System *system = nullptr;

	double Sys_Create()
	{
		result = FMOD::System_Create(&system);      // Create the main system object.
		Util_ErrorChecker();

		std::cout << "FMOD System created" << std::endl;
		return GM_TRUE;
	}

	double Sys_Init()
	{
		result = system->init(512, FMOD_INIT_NORMAL, 0);    // Initialize FMOD.
		Util_ErrorChecker();

		std::cout << "FMOD System initialized" << std::endl;
		return GM_TRUE;
	}

	double Sys_Close()
	{
		result = system->close();
		Util_ErrorChecker();

		result = system->release();
		Util_ErrorChecker();

		std::cout << "FMOD System closed" << std::endl;
		return GM_TRUE;
	}

private:

	double Util_ErrorChecker()
	{
		if (result != FMOD_OK)
		{
			std::cout << "FMOD error! (" << result << ") " << FMOD_ErrorString(result) << std::endl;
			return GM_FALSE;
		}

		return GM_TRUE;
	}
};




