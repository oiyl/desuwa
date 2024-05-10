# desuwa
(extremely unfinished) simple 4chan api wrapper written in c++ 

## example usage
```cpp
/* setup and grab all threads on /lit/ board */
auto lit = std::make_unique<board_t> ( "lit" );

/* empty init ( error ) */
/* auto tech = std::make_unique<board_t> ( ); */
```