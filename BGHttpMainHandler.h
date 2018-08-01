#pragma once

#include "IBGHttpHandler.h"

using namespace std;
using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;

class BGHttpMainHandler
{
public:
	BGHttpMainHandler();
	BGHttpMainHandler(utility::string_t url);

	virtual ~BGHttpMainHandler();

	pplx::task<void> open() { return m_Listener.open(); };
	pplx::task<void> close() { return m_Listener.close(); }

protected:
	void MakeCommand();

private:
	void HandleGet(http_request message);
	void HandlePut(http_request message);
	void HandlePost(http_request message);
	void HandleDelete(http_request message);
	void HandleError(pplx::task<void>& t);

	http_listener m_Listener;

	std::map<std::string, IBGHttpHandler*> m_CommandMap;
	std::mutex m_CommandMapLock;
};

