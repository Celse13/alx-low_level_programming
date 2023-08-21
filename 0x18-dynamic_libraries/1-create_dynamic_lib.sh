#!/bin/bash
gcc -Wall -Wextra -Werror -pedantic -fPIC -c *.c
gcc -shared -o liball.so.0 *.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
