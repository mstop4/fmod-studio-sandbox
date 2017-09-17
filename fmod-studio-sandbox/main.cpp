#include <iostream>
#include "fmodgms.hpp"

int main()
{
	FMODGMS fmodgms;

	std::cout << "Hello World!" << std::endl;

	fmodgms.sys_create();
	fmodgms.sys_initialize();
	fmodgms.snd_loadSound("ffmq-mine.mid");
	fmodgms.snd_playSound(0, 0);

	system("pause");

	fmodgms.sys_close();
	return 0;
}