#! /bin/sh

# Copyright (C) 1996 Darkbot Project.

# This program is free software, you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 2.  This
# program is distributed in the hope that it will be useful, but without
# any warranty, without even the implied warranty of merchantability or
# fitness for a particular purpose.  See the COPYING file for details.


sh bootstrap.sh

DESTDIR="darkbot-`cat VERSION`-CVS-SNAPSHOT"
rm -rf $DESTDIR
rm -f $DESTDIR.tar.gz
mkdir $DESTDIR
cp -p * $DESTDIR 2>/dev/null
cp -p .* $DESTDIR 2>/dev/null
cp -a build dat docs m4 scripts source $DESTDIR
tar cfz build/$DESTDIR.tar.gz $DESTDIR
rm -rf $DESTDIR
