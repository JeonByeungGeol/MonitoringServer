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
* Get 방식의 요청
* </pre>
*/
void BGHttpMainHandler::HandleError(pplx::task<void>& t)
{

}

/**
* <pre>
* Get 방식의 요청
* </pre>
*/
void BGHttpMainHandler::HandleGet(http_request request)
{

};

/**
* <pre>
* 포스트 요청을 처리합니다
* </pre>
* @param request
*/
void BGHttpMainHandler::HandlePost(http_request request)
{
	string strRequest{ BGUtil::ToString(request.to_string()) };
	
	request.extract_json().then([=](pplx::task<web::json::value> t) {
		try
		{
			auto requestValue = t.get();			
			std::string command{ BGUtil::ToString(requestValue[BG_HTTP_COMMAND_KEY].as_string()) };
			if (command.empty()) {
				request.reply(status_codes::OK, L"{\"msg\":\"Not Allowed Command \",\"err\":-1}");
				BG_LOG_ERROR("INVALID HTTP COMMAND : command's handler is not registed [command=%s, body=%s]", command.c_str(), strRequest.c_str());
				return;
			}
			
			m_CommandMapLock.lock();
			auto iter = m_CommandMap.find(command.c_str());
			if (iter == m_CommandMap.end()) {
				BG_LOG_ERROR("INVALID HTTP COMMAND : command's handler is not existed [command=%s]", command.c_str());
				return;
			}
			
			IBGHttpHandler* handler{ nullptr };
			handler = iter->second;

			if (handler == nullptr) {
				BG_LOG_ERROR("INVALID HTTP COMMAND HANDLER : command's hanlder is null [command=%s]", command.c_str());
				return;
			}

			json::value response;
			BG_ERROR::Http error = handler->Process(requestValue, response);
			if (error == BG_ERROR::Http::BG_NONE)
			{
				response[BG_HTTP_KEY_MSG] = json::value::string(BG_HTTP_VALUE_SUCCESS);
				response[BG_HTTP_KEY_ERR] = json::value::number(BG_HTTP_VALUE_ERROR_NONE);
				BG_LOG_DEBUG("HTTP COMMAND HANDLER PROCESS SUCCESS [command=%s]", command.c_str());
			}
			else
			{
				response[BG_HTTP_KEY_MSG] = json::value::string(BG_HTTP_VALUE_FAIL);
				response[BG_HTTP_KEY_ERR] = json::value::number(BG_HTTP_VALUE_ERROR_ETC);
				response[BG_HTTP_KEY_ERROR_DETAIL] = json::value::number(BG_ERROR::ErrorCode(error));
				BG_LOG_ERROR("HTTP COMMAND HANDLER FAIL [command=%s, error= %d]", command.c_str(), BG_ERROR::ErrorCode(error));
			};

			request.reply(status_codes::OK, response.serialize());	
		}
		catch (const std::exception& ex)
		{
			request.reply(status_codes::InternalError, U("EXCEPTION"));
			BG_LOG_ERROR("HTTP COMMAND HANDLER EXCEPTION [error=%s, body=%s]", ex.what(), strRequest.c_str());
		}
		catch (...)
		{
			request.reply(status_codes::InternalError, U("INTERNAL ERROR"));
			BG_LOG_ERROR("HTTP COMMAND HANDLER INTERNAL ERROR [status_codes=%d, body=%s]", status_codes::InternalError, strRequest.c_str());
		};
	});
	
	return;
};

/**
* <pre>
* Delete 방식의 요청
* </pre>
*/
void BGHttpMainHandler::HandleDelete(http_request request)
{

};


/**
* <pre>
* Delete 방식의 요청
* </pre>
*/
void BGHttpMainHandler::HandlePut(http_request request)
{

};


/**
* <pre>
* 커맨드 맵을 만듭니다
* </pre>
*/
void BGHttpMainHandler::MakeCommand()
{
	// m_CommandMap.Add("server_stats", new CSRServerStatsHandler);
}