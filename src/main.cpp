#include "reader/reader.h"
#include "types/board/board.h"
#include "types/thread/thread.h"

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
	auto test_thread = std::make_unique< thread_t > ( lit->board, 23593325 );

	/* get the first reply */
	std::cout << test_thread->get_reply ( 0 ).content;

	/* empty init ( error ) */
	/* auto tech = std::make_unique<board_t> ( ); */

	/* cleanup */
	curl_easy_cleanup ( g_reader.curl );

	return 0;
}
