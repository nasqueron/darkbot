#! /bin/sh

make='make'
if which gmake; then make='gmake'; fi

test ! -r build/configure && sh bootstrap.sh

cd build && sh configure -C --prefix=$HOME/darkbot \
--disable-CTCP --disable-channel --disable-math --disable-google --disable-weather --disable-METAR --disable-TAF --disable-randq --disable-stoned --disable-verbose --disable-random "$@" && \
$make && $make install && cd ..
