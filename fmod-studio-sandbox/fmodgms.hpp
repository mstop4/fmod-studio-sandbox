#pragma once
#include "./fmod_studio_api/fmod.hpp"
#include "./fmod_studio_api/fmod_errors.h"

class FMODGMS
{
public:
	FMOD_RESULT result;

	FMOD::System *system = nullptr;
	FMOD::Channel* channel = nullptr;
	FMOD::Sound* sound = nullptr;

	double Sys_Create();
	double Sys_Init();
	double Sys_Close();

	double Snd_Load(char* filename);
	double Snd_Play(double soundIndex, double channelIndex);

private:
	double Util_ErrorChecker();
};