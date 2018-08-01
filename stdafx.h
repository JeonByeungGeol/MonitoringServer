// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


/*
BG Proto
*/
#include <WinSock2.h>
#include <Windows.h>

// std
#include <iostream>
#include <string>
#include <fstream>

#include <map>
#include <queue>
#include <vector>

#include <thread>
#include <mutex>
#include <shared_mutex>

#include "BGConst.h"
#include "BGSingleton.h"
#include "BGConfigManager.h"
#include "BGLogManager.h"

#include "BGUtil.h"
#include "BGErrorEnum.h"

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.


// CPPRESTSEK
#include <cpprest/json.h>
#include <cpprest/http_listener.h>
#include <cpprest/uri.h>
#include <cpprest/asyncrt_utils.h>
#include <cpprest/http_client.h>