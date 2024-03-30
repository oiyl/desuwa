#pragma once
#include "../main.h"

struct reply_t {

};

struct thread_t {
    /* OP identifying number */
    size_t num;

    /* page on index */
    size_t index_page;

    /* UNIX timestamp of last modification */
    time_t timestamp;

    /* amount of replies */
    size_t replies;
};

struct board_t {
    /* board (/g/) */
    std::string board;

    /* threads */
    std::vector<thread_t> threads;

    auto init ( const std::string board) -> void;

private:
    std::string raw_json;
};

