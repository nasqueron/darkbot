#! /bin/sh

sh bootstrap.sh

if test -z "$NOCONFIGURE"; then
	cd build
	sh configure -C --prefix=$HOME/darkbot "$@"
	cd ..
fi
