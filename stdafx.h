// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
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

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.


// CPPRESTSEK
#include <cpprest/json.h>
#include <cpprest/http_listener.h>
#include <cpprest/uri.h>
#include <cpprest/asyncrt_utils.h>
#include <cpprest/http_client.h>