#pragma once


#include "../desuwa.h"

struct board_t {
	
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

	/* board */
	std::string board;

	/* thread numbers */
	std::vector< int > thread_numbers;

	

private:

	auto init_threads ( ) -> void;

	/* raw data downloaded */
	std::string raw_json; /* should be converted to file system eventually */

	
};