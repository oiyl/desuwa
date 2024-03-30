#include "4chan_types.h"
#include "../reader/reader.h"

auto board_t::init ( const std::string board ) -> void {
	reader::grab_board_threads ( board , this->raw_json );
}