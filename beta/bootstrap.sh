#! /bin/sh

sh clean.sh

mkdir build && \
cp source/configure.ac source/Makefile.am source/compat/*.h source/compat/*.c build && \
mkdir build/dat && \
cp dat/*.ini dat/*.db build/dat && \
mkdir build/dat/rdb && \
cp dat/rdb/*.rdb build/dat/rdb && \
mkdir build/dat/timers
autoreconf -fiv -Wall build
rm -rf build/autom4te.cache
rm -f build/*.c
rm -f build/*.h
