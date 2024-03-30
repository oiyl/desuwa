#pragma once
#include "../main.h"

using json = nlohmann::json;

namespace reader {
    inline CURL* curl;

    auto write_callback ( void* contents , size_t size , size_t nmemb , void* userp );

    /* grab all threads of a board */
    auto grab_board_threads ( std::string board , std::string& result ) -> void;

    /* individual thread */
    auto grab_thread ( std::string board , int num , std::string& result ) -> void;

}
