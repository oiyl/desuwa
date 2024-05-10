#pragma once
#include "../main.h"
#include "../reader/reader.h"

struct reply_t {

};

struct thread_t {
    /* OP identifying number */
    unsigned int num;

    /* UNIX timestamp of last modification */
    time_t timestamp;

    /* amount of replies */
    uint16_t reply_amount;

    /* replies */
    std::vector<reply_t> replies;

    thread_t ( unsigned int a , time_t b , uint16_t c ) : num ( a ) , timestamp ( b ) , replies ( c ) {

    }
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

    explicit board_t ( const std::string& board ) {
        if ( board.empty ( ) or not reader::grab_board_threads ( board , this->raw_json ) ) {
            throw std::invalid_argument ( "improper board provided" );
        }
        init_threads ( );
    }

private:
    std::string raw_json;

    void init_threads ( );
};