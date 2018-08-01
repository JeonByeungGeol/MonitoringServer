#include "stdafx.h"
#include "BGMonitor.h"


BGMonitor::BGMonitor()
	:m_bTimerRunning(false), m_pRunThread(nullptr)
{
}


BGMonitor::~BGMonitor()
{
}

bool BGMonitor::Start()
{
	m_bTimerRunning = true;

	m_pRunThread = RunSpawn();

	return true;
}

bool BGMonitor::Stop()
{
	m_bTimerRunning = false;
	
	if (m_pRunThread) {
		m_pRunThread->join();
		delete m_pRunThread;
		m_pRunThread = nullptr;
	}


	return true;
}

std::thread * BGMonitor::RunSpawn()
{
	return new std::thread{ [this]() { this->Run(); } };
}

void BGMonitor::Run()
{
	BG_LOG_DEBUG("monitor run start");

	while (1) {
		m_RunSharedLock.lock_shared();
		if (m_bTimerRunning == false) {
			m_RunSharedLock.unlock_shared();
			break;
		}
		m_RunSharedLock.unlock_shared();





	}
	
	BG_LOG_DEBUG("monitor run exit");
}

BG_ERROR::Timer BGMonitor::TimerProcess(int type, BGTimerParam params)
{


	return BG_ERROR::Timer::BG_NONE;
}
