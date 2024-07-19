# desuwa
(extremely unfinished) simple 4chan api wrapper written in c++ utilizing CURL

## example usage
```cpp
/* setup and grab all threads on /lit/ board */
auto lit = load_board ( "lit" );

/* grab specified thread and populate replies */
auto test_thread = load_thread( std::move(lit), 23593325 );

/* get the first reply */
std::cout << test_thread->get_reply ( 0 ).content << std::endl;
```
