#include "reader.h"

auto write_callback ( void* contents, size_t size, size_t nmemb, void* userp ) {
	( static_cast< std::string* > ( userp ) )->append ( static_cast< char* > ( contents ), size * nmemb );
	return size * nmemb;
}

auto reader::grab_thread ( std::string board, int num ) -> std::string /* temp, should be to a file */ {
	CURLcode res;
	std::string result;

	std::stringstream ss;
	ss << "https://a.4cdn.org/" << board << "/thread/" << num << ".json";
	std::cout << ss.str ( ) << std::endl;

	curl_easy_setopt ( curl, CURLOPT_URL, ss.str ( ).c_str ( ) );
	curl_easy_setopt ( curl, CURLOPT_WRITEFUNCTION, write_callback );
	curl_easy_setopt ( curl, CURLOPT_WRITEDATA, &result );

	res = curl_easy_perform ( curl );
	if ( res != CURLE_OK ) {
		std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror ( res ) << std::endl;
	}

	/* 404 checking ( invalid board, usually. ) */
	auto response_code = 0u;
	curl_easy_getinfo ( curl, CURLINFO_RESPONSE_CODE, &response_code );
	if ( response_code == 404 ) {
		std::cerr << board << "/thread/" << num << " : 404 not found" << std::endl;
		curl_easy_cleanup ( curl );
	}
	return result;
}

auto reader::grab_board_threads ( std::string board ) -> std::string {
	CURLcode res;
	std::string result;

	std::stringstream ss;
	ss << "https://a.4cdn.org/" << board << "/threads.json";
	std::cout << ss.str ( ) << std::endl;

	curl_easy_setopt ( curl, CURLOPT_URL, ss.str ( ).c_str ( ) );
	curl_easy_setopt ( curl, CURLOPT_WRITEFUNCTION, write_callback );
	curl_easy_setopt ( curl, CURLOPT_WRITEDATA, &result );

	res = curl_easy_perform ( curl );
	if ( res != CURLE_OK ) {
		std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror ( res ) << std::endl;
	}

	/* 404 checking ( invalid board, usually. ) */
	auto response_code = 0;
	curl_easy_getinfo ( curl, CURLINFO_RESPONSE_CODE, &response_code );
	if ( response_code == 404 ) {
		std::cerr << board << " : 404 not found" << std::endl;
		curl_easy_cleanup ( curl );
	}
	return result;
}
