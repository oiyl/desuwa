#pragma once
#include "../main.h"
#include "../reader/reader.h"

struct data {
	std::string of_boards;
};
inline data g_data { };

struct reply_t {
	unsigned int num;
	time_t timestamp;
	std::string content;

	reply_t ( ) { }

	reply_t ( unsigned int a, time_t b, std::string c ) : num ( a ), timestamp ( b ), content ( c ) {
		this->num       = a;
		this->timestamp = b;
		this->content   = c;
	}
};

struct thread_t {
	/* OP identifying number */
	unsigned int num;

	/* UNIX timestamp of last modification */
	time_t timestamp;

	/* amount of replies */
	uint16_t reply_amount;

	/* replies */
	std::vector< std::unique_ptr< reply_t > > replies;

	explicit thread_t ( std::string board, int number ) {
		this->raw_json = g_reader.grab_thread ( board, number );
		init_replies ( );
	}

private:

	/* raw data downloaded */
	std::string raw_json; /* should be converted to file system eventually */

	void init_replies ( );
};

struct board_t {
	/* board */
	std::string board;

	/* thread numbers */
	std::vector< int > thread_numbers;

	// auto refresh ( ) -> void;

	auto get_all_threads ( ) {
		return this->thread_numbers;
	}

	explicit board_t ( ) {
		throw std::invalid_argument ( "no board provided" );
	}

	explicit board_t ( const std::string& board ) {
		if ( board.empty ( ) ) {
			throw std::invalid_argument ( "improper board provided" );
		}
		this->board    = board;
		this->raw_json = g_reader.grab_board_threads ( "lit" );

		init_threads ( );
	}

private:

	/* raw data downloaded */
	std::string raw_json; /* should be converted to file system eventually */

	auto init_threads ( ) -> void;
};