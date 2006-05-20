#! /bin/sh

./autogen.sh

cd build
make && make install
cd ..
