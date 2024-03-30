#include "main.h"
#include <iostream>

namespace reader {
    CURL* curl;

    auto grab_thread ( std::string board , int num , std::string& result );
}

auto write_callback ( void* contents , size_t size , size_t nmemb , void* userp ) {
    ( static_cast< std::string* >( userp ) )->append ( static_cast< char* >( contents ) , size * nmemb );
    return size * nmemb;
}

auto reader::grab_thread ( std::string board , int num , std::string& result ) {
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

int main ( ) {
    reader::curl = curl_easy_init ( );
    if ( !reader::curl ) {
        std::cerr << "Failed to initialize curl" << std::endl;
        return 1;
    }

    std::string initial , second_thread;

    reader::grab_thread ( "g" , 99720485 , initial );
    reader::grab_thread ( "wsg" , 957536 , second_thread );

    std::cout << initial << std::endl;
    std::cout << second_thread << std::endl;

    curl_easy_cleanup ( reader::curl );

    return 0;
}
