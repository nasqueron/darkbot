#! /bin/sh

cd build
./configure -C --prefix=$HOME/darkbot "$@" && make && make install
cd ..
