#pragma once

class IBGHttpHandler
{
public:
	virtual BG_ERROR::Http Process(const web::json::value& request, web::json::value& response) = 0;
};