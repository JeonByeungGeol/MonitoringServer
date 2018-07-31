#include "stdafx.h"
#include "BGHttpServer.h"
#include "BGHttpMainHandler.h"

using namespace std;
using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;

BGHttpServer::BGHttpServer()
	: m_pHttpHandler(nullptr)
{
}


BGHttpServer::~BGHttpServer()
{
}

bool BGHttpServer::Start()
{	
	// web 서버 주소 설정
	std::string localIP = g_Config.GetString("LOCAL_IP");
	std::string webName = g_Config.GetString("WEB.Name");
	std::string webPort = g_Config.GetString("WEB.Port");

	// str format
	ostringstream os;
	os << "http://" << localIP << ":" << webPort << "/" << webName << "/";
	std::string url{ os.str() };

	// str -> wstr 변환
	std::wstring wstr;
	wstr.assign(url.begin(), url.end());
	
	string_t address{ wstr };
	uri_builder uri(address);
	auto addr = uri.to_uri().to_string();
	m_pHttpHandler = new BGHttpMainHandler(addr);

	m_pHttpHandler->open().wait();

	return true;
}

bool BGHttpServer::Stop()
{
	if (m_pHttpHandler) {
		m_pHttpHandler->close().wait();

		delete m_pHttpHandler;
		m_pHttpHandler = nullptr;
	}

	return true;
}
