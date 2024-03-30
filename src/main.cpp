#include "reader/reader.h"
#include "types/4chan_types.h"

int main ( ) {
    /* init curl */
    reader::curl = curl_easy_init ( );
    if ( !reader::curl ) {
        std::cerr << "Failed to initialize curl" << std::endl;
        return 1;
    }

    /* test board implementation*/
    board_t literature;

    /* grabs all threads on /lit/ board */
    literature.init ( "lit" );

    /* cleanup */
    curl_easy_cleanup ( reader::curl );

    return 0;
}
