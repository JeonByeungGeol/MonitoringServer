#pragma once

class IBGHttpHandler
{
public:
	virtual void Process(const web::json::value& request, web::json::value& response) = 0;
};