#! /bin/sh

./bootstrap.sh

if test -z "$NOCONFIGURE"; then
	cd build
	./configure -C --prefix=$HOME/darkbot "$@"
	cd ..
fi
