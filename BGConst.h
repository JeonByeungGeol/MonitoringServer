#pragma once

/** ���� ���� �̸� */
static const char* const BG_CONFIG_FILE_NAME = "bg_config.ini";

/** ���� Ǯ ũ�� : 10001�� ���� Ǯ ����*/
static const int BG_SESSION_POOL_SIZE = 10001;

/** Ÿ�̸ӿ��� ������ ������ ����*/
static const int BG_TIMER_THREAD_NUM = 1;


// -------------------------->
// HTTP Server ����
// -------------------------->

/** HTTP COMMAND KEY */
static const wchar_t* const BG_HTTP_COMMAND_KEY = L"cmd";

/** HTTP MSG */
static const wchar_t* const BG_HTTP_KEY_MSG = L"msg";

/** HTTP ERR */
static const wchar_t* const BG_HTTP_KEY_ERR = L"err";

/** HTTP ������ ���� ��ȣ */
static const wchar_t* const BG_HTTP_KEY_ERROR_DETAIL = L"error-detail";

/** HTTP VALUE success */
static const wchar_t* const BG_HTTP_VALUE_SUCCESS = L"success";

/** HTTP VALUE fail */
static const wchar_t* const BG_HTTP_VALUE_FAIL = L"fail";

/** HTTP VALUE ���� */
static const int BG_HTTP_VALUE_ERROR_NONE = 0;

/** HTTP VALUE ��Ÿ ���� */
static const int BG_HTTP_VALUE_ERROR_ETC = -1;
