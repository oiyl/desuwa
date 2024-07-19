#include "thread.h"

auto thread_t::get_reply ( size_t index ) -> reply_t& {
	return *replies.at ( index );
}

auto thread_t::init_replies ( ) -> void {
	try {
		json json_data = json::parse ( this->raw_json );

		if ( json_data.is_object ( ) ) {
			if ( json_data.find ( "posts" ) != json_data.end ( ) && json_data[ "posts" ].is_array ( ) ) {
				for ( const auto& reply : json_data[ "posts" ] ) {
					if ( reply.find ( "no" ) != reply.end ( ) && reply.find ( "time" ) != reply.end ( ) && reply.find ( "com" ) != reply.end ( ) ) {
						unsigned int num    = reply[ "no" ];
						time_t time         = reply[ "time" ];
						std::string content = reply[ "com" ];

						replies.emplace_back ( std::make_unique< reply_t > ( num, time, content ) );
					}
				}
			}
		}
	} catch ( const std::exception& e ) {
		std::cerr << "Exception during JSON parsing: " << e.what ( ) << std::endl;
	}
}
