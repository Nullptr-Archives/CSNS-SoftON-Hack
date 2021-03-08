#include <Windows.h>
#include "Interface.h"

CreateInterfaceFn CaptureFactory(char* FactoryModule) {
	CreateInterfaceFn Interface = 0;

	while (!Interface) {
		HMODULE hFactoryModule = GetModuleHandleA(FactoryModule);

		if (hFactoryModule)
			Interface = (CreateInterfaceFn)(GetProcAddress(hFactoryModule, "CreateInterface"));

		Sleep(100);
	}

	return Interface;
}

PVOID CaptureInterface(CreateInterfaceFn Interface, char* InterfaceName) {
	PVOID dwPointer = nullptr;

	while (!dwPointer) {
		dwPointer = (PVOID)(Interface(InterfaceName, 0));
		Sleep(100);
	}

	return dwPointer;
}