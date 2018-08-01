#pragma once

/** 설정 파일 이름 */
static const char* const BG_CONFIG_FILE_NAME = "bg_config.ini";

/** 세션 풀 크기 : 10001개 세션 풀 유지*/
static const int BG_SESSION_POOL_SIZE = 10001;

/** 타이머에서 동작할 스레드 갯수*/
static const int BG_TIMER_THREAD_NUM = 1;


// -------------------------->
// HTTP Server 관련
// -------------------------->

/** HTTP COMMAND KEY */
static const wchar_t* const BG_HTTP_COMMAND_KEY = L"cmd";

/** HTTP MSG */
static const wchar_t* const BG_HTTP_KEY_MSG = L"msg";

/** HTTP ERR */
static const wchar_t* const BG_HTTP_KEY_ERR = L"err";

/** HTTP 점령전 에러 번호 */
static const wchar_t* const BG_HTTP_KEY_ERROR_DETAIL = L"error-detail";

/** HTTP VALUE success */
static const wchar_t* const BG_HTTP_VALUE_SUCCESS = L"success";

/** HTTP VALUE fail */
static const wchar_t* const BG_HTTP_VALUE_FAIL = L"fail";

/** HTTP VALUE 정상 */
static const int BG_HTTP_VALUE_ERROR_NONE = 0;

/** HTTP VALUE 기타 에러 */
static const int BG_HTTP_VALUE_ERROR_ETC = -1;
