#include "reader/reader.h"
#include "types/board/board.h"
#include "types/thread/thread.h"

auto load_board ( const std::string& name ) {
	if ( name.empty ( ) ) {
		throw std::invalid_argument ( "load_board(): improper board name" );
	}
	return std::make_unique< board_t > ( name );
}

auto load_thread ( std::unique_ptr< board_t > board, size_t num ) {
	return std::make_unique< thread_t > ( board->board, num );
}

int main ( ) {
	/* init curl */
	g_reader.curl = curl_easy_init ( );

	if ( !g_reader.curl ) {
		std::cerr << "Failed to initialize curl" << std::endl;
		return 1;
	}

	/* setup and grab all threads on /lit/ board */
	auto lit = load_board ( "lit" );

	/* grab specified thread and populate replies */
	auto test_thread = load_thread ( std::move ( lit ), 23593325 );

	/* get the first reply */
	std::cout << test_thread->get_reply ( 0 ).content << std::endl;

	/* cleanup */
	curl_easy_cleanup ( g_reader.curl );

	return 0;
}
