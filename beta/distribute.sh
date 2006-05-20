#! /bin/sh

./bootstrap.sh

DESTDIR="darkbot-`cat VERSION`" 
rm -rf $DESTDIR
mkdir $DESTDIR
cp -p * $DESTDIR 2>/dev/null
cp -p .* $DESTDIR 2>/dev/null
cp -a build dat docs m4 scripts source $DESTDIR
rm -rf $DESTDIR/build/autom4te.cache
tar cfz build/$DESTDIR.tar.gz $DESTDIR
rm -rf $DESTDIR
