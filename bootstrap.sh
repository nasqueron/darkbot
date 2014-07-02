#! /bin/sh

# Copyright (C) 1996 Darkbot Project.

# This program is free software, you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 2.  This
# program is distributed in the hope that it will be useful, but without
# any warranty, without even the implied warranty of merchantability or
# fitness for a particular purpose.  See the COPYING file for details.


sh clean.sh

mkdir build && \
cp source/configure.ac source/Makefile.am build && \
mkdir build/compat && \
mkdir build/dat && \
cp dat/*.ini dat/*.db build/dat && \
mkdir build/dat/rdb && \
cp dat/rdb/*.rdb build/dat/rdb && \
mkdir build/dat/timers && \
autoreconf -fiv -Wall build
rm -rf build/autom4te.cache
rm -f build/*.c
rm -f build/*.h
