// BGPrototype.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

	if (!g_Timer.Start()) {
		BG_LOG_ERROR("g_Timer.Start failed");
		return -1;
	}

	if (!g_Monitor.Start()) {
		BG_LOG_ERROR("g_Monitor.Start failed");
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

	if (!g_Monitor.Stop()) {
		BG_LOG_ERROR("g_Monitor.Stop failed");
		return -1;
	}

	if (!g_Timer.Stop()) {
		BG_LOG_ERROR("g_Timer.Stop failed");
		return -1;
	}

	if (!g_LogManager.Stop()) {
		std::cout << "g_LogManager.Stop failed" << std::endl;
		return -1;
	}

	return 0;
}