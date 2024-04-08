#include "4chan_types.h"

void board_t::init_threads ( ) {
    json json_data = json::parse ( raw_json );
    for ( const auto& page : json_data ) {
        if ( page.find ( "threads" ) != page.end ( ) ) {
            for ( const auto& thread : page [ "threads" ] ) {
                unsigned int num = thread [ "no" ];
                time_t last_modified = thread [ "last_modified" ];
                uint16_t replies = thread [ "replies" ];

                threads.emplace_back ( thread_t ( num , last_modified , replies ) );

            }
        }
    }
}