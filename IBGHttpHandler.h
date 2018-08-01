#pragma once

class IBGHttpHandler
{
public:
	virtual HttpError Process(const web::json::value& request, web::json::value& response) = 0;
};