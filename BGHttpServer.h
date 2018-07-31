#pragma once

#include "cpprest/json.h"
#include "cpprest/http_listener.h"
#include "cpprest/uri.h"
#include "cpprest/asyncrt_utils.h"
#include "cpprest/filestream.h"
#include "cpprest/containerstream.h"
#include "cpprest/producerconsumerstream.h"

#include "BGHttpMainHandler.h"

class BGHttpServer
{
public:
	BGHttpServer();
	virtual ~BGHttpServer();

	bool Start();

	bool Stop();

private:
	BGHttpMainHandler* m_pHttpHandler;
};

