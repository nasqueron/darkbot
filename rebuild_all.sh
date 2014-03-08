#! /bin/sh

make='gmake'
if [ -z "$(which gmake 1>/dev/null 2>&1)" ]; then make='make'; fi

sh autogen.sh

cd build && $make && $make install && cd ..
