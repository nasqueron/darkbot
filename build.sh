#! /bin/sh

make='gmake'
if [ -z "$(which gmake 1>/dev/null 2>&1)" ]; then make='make'; fi

test ! -r build/configure && sh bootstrap.sh

cd build && sh configure -C --prefix=$HOME/darkbot "$@" && $make && $make install && cd ..
