#! /bin/sh

make='make'
if which gmake; then make='gmake'; fi

sh autogen.sh

cd build && $make && $make install && cd ..
