#! /bin/sh

test ! -r build/configure && sh bootstrap.sh

cd source && sh configure -C --prefix=$HOME/darkbot "$@" && make && make install && cd ..
