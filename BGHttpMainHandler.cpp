#include "stdafx.h"
#include "BGHttpMainHandler.h"

// Handler
BGHttpMainHandler::BGHttpMainHandler()
{
}

BGHttpMainHandler::BGHttpMainHandler(utility::string_t url)
	: m_Listener(url)
{
	//m_Listener.support(methods::GET, std::bind(&BGHttpMainHandler::HandleGet, this, std::placeholders::_1));
	//m_Listener.support(methods::PUT, std::bind(&BGHttpMainHandler::HandlePut, this, std::placeholders::_1));
	m_Listener.support(web::http::methods::POST, std::bind(&BGHttpMainHandler::HandlePost, this, std::placeholders::_1));
	//m_Listener.support(methods::DEL, std::bind(&BGHttpMainHandler::HandleDelete, this, std::placeholders::_1));

	MakeCommand();
}

BGHttpMainHandler::~BGHttpMainHandler()
{
	for (auto data : m_CommandMap) {
		auto ptr = data.second;
		if (ptr) {
			delete ptr;
			ptr = nullptr;
		}
	}
	m_CommandMap.clear();
}

/**
* <pre>
* Get ����� ��û
* </pre>
*/
void BGHttpMainHandler::HandleError(pplx::task<void>& t)
{

}

/**
* <pre>
* Get ����� ��û
* </pre>
*/
void BGHttpMainHandler::HandleGet(http_request request)
{

};

/**
* <pre>
* ����Ʈ ��û�� ó���մϴ�
* </pre>
* @param request
*/
void BGHttpMainHandler::HandlePost(http_request request)
{
	
	return;
};

/**
* <pre>
* Delete ����� ��û
* </pre>
*/
void BGHttpMainHandler::HandleDelete(http_request request)
{

};


/**
* <pre>
* Delete ����� ��û
* </pre>
*/
void BGHttpMainHandler::HandlePut(http_request request)
{

};


/**
* <pre>
* Ŀ�ǵ� ���� ����ϴ�
* </pre>
*/
void BGHttpMainHandler::MakeCommand()
{
	// m_CommandMap.Add(L"server_stats", new CSRServerStatsHandler);
}