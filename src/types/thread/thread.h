#pragma once

#include "../desuwa.h"
#include "../reply/reply.h"

struct thread_t {
	explicit thread_t ( std::string board, int number ) {
		this->raw_json = g_reader.grab_thread ( board, number );
		init_replies ( );
	}

	auto get_reply ( size_t index ) -> reply_t&;

	/* OP identifying number */
	unsigned int num;

	/* UNIX timestamp of last modification */
	time_t timestamp;

	/* amount of replies */
	uint16_t reply_amount;

	/* replies */
	std::vector< std::unique_ptr< reply_t > > replies;

private:

	void init_replies ( );

	/* raw data downloaded */
	std::string raw_json; /* should be converted to file system eventually */

	
};
