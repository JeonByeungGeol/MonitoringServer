#pragma once
class BGMonitor : public IBGTimerObject
{
public:
	BGMonitor();
	~BGMonitor();

public:
	/** 서버 모니터를 시작합니다.*/
	bool Start();
	
	/** 서버 모니터를 종료합니다.*/
	bool Stop();

	

	virtual BG_ERROR::Timer TimerProcess(int type, BGTimerParam params);


private:
	/** 모니터가 동작하고 있는지 나타내는 값과 그 값을 동기화 하기 위한 뮤텍스*/
	std::shared_mutex m_RunSharedLock;
	bool m_bTimerRunning;

	/** 실질적으로 서버를 모니터 하는 스레드 함수의 포인트*/
	std::thread* m_pRunThread;

	/** 스레드에서 동작할 멤버함수(Run)  생성*/
	std::thread* RunSpawn();

	/** 타이머에서 동작할 스레드 입니다. */
	void Run();
};

