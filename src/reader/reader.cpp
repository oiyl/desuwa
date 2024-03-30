#include "reader.h"

auto reader::write_callback ( void* contents , size_t size , size_t nmemb , void* userp ) {
    ( static_cast< std::string* >( userp ) )->append ( static_cast< char* >( contents ) , size * nmemb );
    return size * nmemb;
}

auto reader::grab_thread ( std::string board , int num , std::string& result ) -> void {
    CURLcode res;
    result.clear ( );

    std::stringstream ss;
    ss << "https://a.4cdn.org/" << board << "/thread/" << num << ".json";
    std::cout << ss.str ( ) << std::endl;

    curl_easy_setopt ( curl , CURLOPT_URL , ss.str ( ).c_str ( ) );
    curl_easy_setopt ( curl , CURLOPT_WRITEFUNCTION , write_callback );
    curl_easy_setopt ( curl , CURLOPT_WRITEDATA , &result );

    res = curl_easy_perform ( curl );
    if ( res != CURLE_OK ) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror ( res ) << std::endl;
    }
}

auto reader::grab_board_threads ( std::string board , std::string& result ) -> void {
    CURLcode res;
    result.clear ( );

    std::stringstream ss;
    ss << "https://a.4cdn.org/" << board << "/threads.json";
    std::cout << ss.str ( ) << std::endl;

    curl_easy_setopt ( curl , CURLOPT_URL , ss.str ( ).c_str ( ) );
    curl_easy_setopt ( curl , CURLOPT_WRITEFUNCTION , write_callback );
    curl_easy_setopt ( curl , CURLOPT_WRITEDATA , &result );

    res = curl_easy_perform ( curl );
    if ( res != CURLE_OK ) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror ( res ) << std::endl;
    }
}