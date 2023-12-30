#!/bin/bash
wget -P .. https://githubusercontent.com/Gloriah-B/alx-low_level_programming/master/0x18-dynamic_libraries/liball.so
export LD_PRELOAD="&PWD/../libhack.so"
