#! /bin/sh

make='make'
if which gmake; then make='gmake'; fi

test ! -r build/configure && sh bootstrap.sh

cd build && sh configure -C --prefix=$HOME/darkbot --enable-testing "$@" && $make && $make install && cd ..
