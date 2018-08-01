#pragma once
class BGMonitor : public IBGTimerObject
{
public:
	BGMonitor();
	~BGMonitor();

public:
	/** ���� ����͸� �����մϴ�.*/
	bool Start();
	
	/** ���� ����͸� �����մϴ�.*/
	bool Stop();

	

	virtual BG_ERROR::Timer TimerProcess(int type, BGTimerParam params);


private:
	/** ����Ͱ� �����ϰ� �ִ��� ��Ÿ���� ���� �� ���� ����ȭ �ϱ� ���� ���ؽ�*/
	std::shared_mutex m_RunSharedLock;
	bool m_bTimerRunning;

	/** ���������� ������ ����� �ϴ� ������ �Լ��� ����Ʈ*/
	std::thread* m_pRunThread;

	/** �����忡�� ������ ����Լ�(Run)  ����*/
	std::thread* RunSpawn();

	/** Ÿ�̸ӿ��� ������ ������ �Դϴ�. */
	void Run();
};

