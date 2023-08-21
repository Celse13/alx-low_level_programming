#!/bin/bash
gcc -Wall -Wextra -Werror -pedantic-fPIC
gco -shared -o liball.so.0 
export LD LIBRARY PATH=.:$LD LIBRARY_PATH
