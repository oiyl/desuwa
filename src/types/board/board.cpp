#include "board.h"

void board_t::init_threads ( ) {
	try {
		json json_data = json::parse ( this->raw_json );

		for ( const auto& page : json_data ) {
			if ( page.find ( "threads" ) != page.end ( ) ) {
				for ( const auto& thread : page[ "threads" ] ) {
					unsigned int num = thread[ "no" ];

					thread_numbers.emplace_back ( num );
				}
			}
		}
	} catch ( const std::exception& e ) {
		std::cerr << "Exception during JSON parsing: " << e.what ( ) << std::endl;
	}
}