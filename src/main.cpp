#include "reader/reader.h"
#include "types/4chan_types.h"

int main ( ) {
    /* init curl */
    reader::curl = curl_easy_init ( );
    if ( !reader::curl ) {
        std::cerr << "Failed to initialize curl" << std::endl;
        return 1;
    }

    /* setup and grab all threads on /lit/ board */
    auto lit = std::make_unique<board_t> ( "lit" );

    /* empty init ( error ) */
    /* auto tech = std::make_unique<board_t> ( ); */

    /* cleanup */
    curl_easy_cleanup ( reader::curl );

    return 0;
}
