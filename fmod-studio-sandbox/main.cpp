#include <iostream>
#include "fmodgms.cpp"

int main()
{
	int foo;
	FMODGMS fmodgms;

	std::cout << "Hello World!" << std::endl;

	fmodgms.Sys_Create();
	fmodgms.Sys_Init();

	std::cin >> foo;

	fmodgms.Sys_Close();

	std::cin >> foo;
	return 0;
}