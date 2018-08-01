#pragma once

#include "BGConfigManager.h"
#include "BGLogManager.h"
#include "BGTimer.h"

#include "BGHttpServer.h"

/**
 * std::once_flag�� �ʱ�ȭ ���� ������ std::call_once�� �����Ǿ� ��Ƽ������ ȯ�濡��
 * �� �ѹ��� ����Ǵ� ���� �ü�� �������� ������ �ֵ��� �����Ǿ���.
 * �����Ϸ��� ����� �ִ� Ŭ������ ���� �����ڳ� �Ҵ� �����ڸ� ���� ���� ����(Deep copy)��
 * �����ϴ� ���� �ø�ƽ(Copy Semantics)�� �Ͼ��. ������ ���Ϳ� ���� �����̳ʿ� �۾���
 * �����ϸ� ���� ��ü�� ������� �ʰ� �Ǿ� ���� �߻��Ѵ�. ������ ������ ���� ����(Shallow copy)����
 * ������ ���� ��ü�� ����� �������� ������Ű�� �̵� �ø�ƽ(Move Semantics)�� �Ͼ�µ�,
 * ��ǥ������ �̵� �����ڳ� unique_ptr�� �ִ�. unique_ptr���� ���� �����ڳ� �Ҵ� �����ڰ� ���� ������
 * std::move()�� ����ϰų� reset() �޼ҵ带 �̿��� ��ü�� �Ҵ��ϸ� ����Ʈ �����ͱ� ������ �ڿ������� �����ϴ�.
*/

/**
 * <pre>
 * �̱������� ������ �� �ʿ䰡 �ִ� ��ü����
 * �� ��ü�ȿ� �ִ´�.
 * ���� �̱��� ��ü�� ����� ���� ���� �����ϱ� ����
 * ũ�Ⱑ �ʹ� ū ��ü���� ���� �ʴ´�...
 * </pre>
*/

/** define���� ����*/
#define g_Config BGSingleton::Instance()->GetConfigManager()
#define g_LogManager BGSingleton::Instance()->GetLogManager()
#define g_Timer BGSingleton::Instance()->GetTimer()

/** ����� ����*/
#define g_HttpServer BGSingleton::Instance()->GetHttpServer()

class BGSingleton
{
//////////////////////////////////////////////////
	/** �̱��� ���� ��*/
private:
	static std::once_flag onceflag_;
	static std::unique_ptr<BGSingleton> instance_;
	
protected:
	BGSingleton() = default;
	BGSingleton(const BGSingleton&) = delete;
	BGSingleton& operator=(const BGSingleton&) = delete;

public:
	static BGSingleton* Instance() {
		std::call_once(onceflag_, []() {
			instance_.reset(new BGSingleton);
		});
		return instance_.get();
	}
//////////////////////////////////////////////////


	/** �̱������� ������ ��ü*/
private:
	BGConfigManager m_ConfigManager;
	BGLogManager m_LogManager;
	BGTimer m_Timer;

	BGHttpServer m_HttpServer;

public:
	BGConfigManager& GetConfigManager() { return m_ConfigManager; }
	BGLogManager& GetLogManager() { return m_LogManager; }
	BGTimer& GetTimer() { return m_Timer; }

	BGHttpServer& GetHttpServer() { return m_HttpServer; }

};

