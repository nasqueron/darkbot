#! /bin/sh

sh clean.sh

mkdir build && cp source/configure.ac source/Makefile.am source/compat/*.h source/compat/*.c build && cp -a dat build
autoreconf -fiv -Wall -Werror build
rm -rf build/autom4te.cache
