// BGPrototype.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	if (!g_Config.Load()) {
		std::cout << "g_Config.Load failed" << std::endl;
		return -1;
	}

	if (!g_LogManager.Start()) {
		std::cout << "g_LogManager.Start failed" << std::endl;
		return -1;
	}

	BG_LOG_TRACE("START");

	while (1)
	{
		char c;
		std::cin >> c;
		if (c == 'e')
		{
			break;
		}
		Sleep(1000);
	}

	BG_LOG_TRACE("END");

	if (!g_LogManager.Stop()) {
		std::cout << "g_LogManager.Stop failed" << std::endl;
		return -1;
	}

	return 0;
}