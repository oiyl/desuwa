# desuwa
(extremely unfinished) simple 4chan api wrapper written in c++ utilizing CURL

## example usage
```cpp
/* setup and grab all threads on /lit/ board */
auto lit = std::make_unique< board_t > ( "lit" );

/* grab specified thread and populate replies */
auto test = std::make_unique< thread_t > ( lit->board, 23593325 );

/* empty init ( error ) */
/* auto tech = std::make_unique<board_t> ( ); */
```
