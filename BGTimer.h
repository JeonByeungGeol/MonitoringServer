#pragma once

#include "IBGTimerObject.h"
#include "TestTimerObject.h"

struct BGTimerParam
{
	void* param1;
	void* param2;
	void* param3;
	void* param4;
};

class BGTimerToken
{
public:
	BGTimerToken(__int64 milSec, IBGTimerObject* pObject, int type, BGTimerParam params)
		: m_ExecTime(milSec), m_Object(pObject), m_TimerEventType(type), m_Params(params)
	{
	}

public:
	__int64 m_ExecTime;

	IBGTimerObject* m_Object;
	int m_TimerEventType;
	BGTimerParam m_Params;
};

struct Compare {
	bool operator()(const BGTimerToken* ref1, const BGTimerToken* ref2)
	{
		return ref1->m_ExecTime > ref2->m_ExecTime;
	}
};

class BGTimer
{
	using TimerToken = BGTimerToken*;
	using TimerQueue = std::priority_queue < TimerToken, std::vector<TimerToken>, Compare> ;

public:
	BGTimer();
	~BGTimer();

public:
	// Ÿ�̸� �ý����� �����մϴ�.
	bool Start();

	// Ÿ�̸� �ý����� �����մϴ�.
	bool Stop();
		
	/** Ÿ�̸� �۾� �߰� */
	void Push(__int64, IBGTimerObject*, int, BGTimerParam);


private:
	/** Ÿ�̸Ӱ� �����ϰ� �ִ��� ��Ÿ���� ���� �� ���� ����ȭ �ϱ� ���� ���ؽ�*/
	std::shared_mutex m_RunSharedLock;
	bool m_bTimerRunning;

	/** Ư�� �ð��� �۾��ؾ� �ϴ� ���� ������ �ִ� ť�� ����ȭ �ϱ� ���� ���ؽ�*/
	std::mutex m_queueLock;
	TimerQueue m_queue;

	/** ���������� �����ϴ� ������ �Լ��� ����Ʈ*/
	std::vector<std::thread*> m_vecRunThread;
	
	/** �����忡�� ������ ����Լ�(Run)  ����*/
	std::thread* RunSpawn();

	/** Ÿ�̸ӿ��� ������ ������ �Դϴ�. */
	void Run();
};

