#pragma once

#include "../desuwa.h"

struct reply_t {
	reply_t ( ) { }

	reply_t ( unsigned int a, time_t b, std::string c ) : num ( a ), timestamp ( b ), content ( c ) {
		this->num       = a;
		this->timestamp = b;
		this->content   = c;
	}

	~reply_t ( ) { };

	unsigned int num;
	time_t timestamp;
	std::string content;
};