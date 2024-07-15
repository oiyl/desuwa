#include "reader/reader.h"
#include "types/4chan_types.h"

int main ( ) {
	/* init curl */
	g_reader.curl = curl_easy_init ( );

	if ( !g_reader.curl ) {
		std::cerr << "Failed to initialize curl" << std::endl;
		return 1;
	}

	/* setup and grab all threads on /lit/ board */
	auto lit = std::make_unique< board_t > ( "lit" );

	/* grab specified thread and populate replies */
	auto test = std::make_unique< thread_t > ( lit->board, 23593325 );

	/* empty init ( error ) */
	/* auto tech = std::make_unique<board_t> ( ); */

	/* cleanup */
	curl_easy_cleanup ( g_reader.curl );

	return 0;
}
