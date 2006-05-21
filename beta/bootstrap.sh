#! /bin/sh

./clean.sh

mkdir build && cp source/configure.ac source/Makefile.am build && cp -a dat build && autoreconf -fiv -Wall -Werror build
rm -rf build/autom4te.cache
