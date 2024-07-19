#pragma once

/* messy curl stuff */
#define CURL_STATICLIB
#include "curl/debug/curl.h"

#ifdef _DEBUG
#	pragma comment( lib, "curl/debug/libcurl_a_debug.lib" )
#else
#	pragma comment( lib, "curl/release/libcurl_a.lib" )
#endif

#pragma comment( lib, "Normaliz.lib" )
#pragma comment( lib, "Ws2_32.lib" )
#pragma comment( lib, "Wldap32.lib" )
#pragma comment( lib, "Crypt32.lib" )
#pragma comment( lib, "advapi32.lib" )

/* json */
#include "json.hpp"

#include <iostream>
#include <string>
