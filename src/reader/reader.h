#pragma once
#include "../main.h"

using json = nlohmann::json;

/* handle CURL respone data */
auto write_callback ( void* contents, size_t size, size_t nmemb, void* userp );

struct reader {
public:

	/* grab all threads of a board */
	auto grab_board_threads ( std::string board ) -> std::string;

	/* individual thread */
	auto grab_thread ( std::string board, int num ) -> std::string;

	/* curl instance */
	CURL* curl;
};

inline extern reader g_reader { };