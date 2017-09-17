#include <iostream>
#include "fmodgms.hpp"

int main()
{
	FMODGMS fmodgms;

	std::cout << "Hello World!" << std::endl;

	fmodgms.Sys_Create();
	fmodgms.Sys_Init();
	fmodgms.Snd_Load("ffmq-mine.mid");
	fmodgms.Snd_Play(0, 0);

	system("pause");

	fmodgms.Sys_Close();
	return 0;
}