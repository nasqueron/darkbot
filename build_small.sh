#! /bin/sh

make='gmake'
if [ -z "$(which gmake 1>/dev/null 2>&1)" ]; then make='make'; fi

test ! -r build/configure && sh bootstrap.sh

cd build && sh configure -C --prefix=$HOME/darkbot \
--disable-CTCP --disable-channel --disable-math --disable-google --disable-weather --disable-METAR --disable-TAF --disable-randq --disable-stoned --disable-verbose --disable-random "$@" && \
$make && $make install && cd ..
