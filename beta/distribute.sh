#! /bin/sh

sh bootstrap.sh

DESTDIR="darkbot-`cat VERSION`" 
rm -rf $DESTDIR
mkdir $DESTDIR && \
cp -p * $DESTDIR 2>/dev/null && \
cp -p .* $DESTDIR 2>/dev/null && \
cp -a build dat docs m4 scripts source $DESTDIR && \
tar cfz build/$DESTDIR.tar.gz $DESTDIR && \
rm -rf $DESTDIR
