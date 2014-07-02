#! /bin/sh

# Copyright (C) 1996 Darkbot Project.

# This program is free software, you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 2.  This
# program is distributed in the hope that it will be useful, but without
# any warranty, without even the implied warranty of merchantability or
# fitness for a particular purpose.  See the COPYING file for details.


sh bootstrap.sh

if test -z "$NOCONFIGURE"; then
	cd build && sh configure -C --prefix=$HOME/darkbot "$@" && cd ..
fi
