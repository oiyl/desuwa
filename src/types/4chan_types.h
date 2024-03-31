#pragma once
#include "../main.h"
#include "../reader/reader.h"

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
 
    //auto refresh ( ) -> void;

    explicit board_t ( ) {
        throw std::invalid_argument ( "no board provided" );
    }

    explicit board_t ( const std::string& board ) : board ( board ) { 
        if ( board.empty ( ) or not reader::grab_board_threads ( board , this->raw_json ) ) {
            throw std::invalid_argument ( "improper board provided" );
        }
    }

private:
    std::string raw_json;
};

