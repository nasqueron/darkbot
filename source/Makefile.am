## Process this file with automake to produce Makefile.in.

## Top level diectory.
topdir = @srcdir@/..
db_db = $(topdir)/dat
db_src = $(topdir)/source
cm_src = $(topdir)/source/compat
db_scripts = $(topdir)/scripts
VPATH = @srcdir@/../source @srcdir@/../source/compat

## Database location.
databasedir = $(localstatedir)/@PACKAGE@

## Setup options for other programs.
ACLOCAL_AMFLAGS = -I ../m4
AM_CPPFLAGS = -I $(db_src) -I $(cm_src) -DDATABASEDIR='"$(databasedir)"' -DSOURCEDIR='"@srcdir@"'

## Compatability library.
noinst_LIBRARIES = compat/libcompat.a
compat_libcompat_a_SOURCES = $(cm_src)/dummy.c
compat_libcompat_a_LIBADD = @LIBOBJS@

## Darkbot server.
bin_PROGRAMS = darkbot convertdb
darkbot_SOURCES = $(db_src)/chan.c $(db_src)/general.c $(db_src)/permbans.c $(db_src)/reserved.c $(db_src)/sockets.c \
                  $(db_src)/users.c $(db_src)/chansrv.c $(db_src)/helpers.c $(db_src)/quiz.c $(db_src)/seen.c $(db_src)/stats.c \
                  $(db_src)/vars.c $(db_src)/comm.c $(db_src)/main.c $(db_src)/random.c $(db_src)/server.c $(db_src)/topics.c $(db_src)/web.c \
                  $(db_src)/parse.c $(db_src)/raw.c $(db_src)/signals.c $(db_src)/url.c \
                  $(db_src)/langs/*.h \
                  $(db_src)/prototypes.h $(db_src)/vars.h
darkbot_LDADD = compat/libcompat.a

## Utility programs.
convertdb_SOURCES = $(db_src)/convertdb.c
convertdb_LDADD = compat/libcompat.a
dist_bin_SCRIPTS = $(db_scripts)/AddServer $(db_scripts)/AddUser $(db_scripts)/check-integrity $(db_scripts)/dbcron $(db_scripts)/download-databases \
                  $(db_scripts)/kill.darkbot $(db_scripts)/live-update $(db_scripts)/restart.darkbot $(db_scripts)/Setup

## databases.
dist_database_DATA = $(db_db)/deop.ini $(db_db)/info2.db $(db_db)/perform.ini $(db_db)/permbans.db $(db_db)/quiz.db $(db_db)/random.ini \
                  $(db_db)/randomstuff.ini $(db_db)/servers.ini $(db_db)/setup.ini $(db_db)/stats.db $(db_db)/userlist.db
rdbdir = $(databasedir)/rdb
dist_rdb_DATA = $(db_db)/rdb/dunno.rdb $(db_db)/rdb/whut.rdb

timersdir = $(databasedir)/timers

## Documentation.
## docdir = $(datadir)/doc/@PACKAGE@
doc_DATA = $(topdir)/COPYING $(topdir)/docs/INSTALL $(topdir)/README $(topdir)/VERSION $(topdir)/docs/AUTHORS $(topdir)/docs/HACKING \
                  $(topdir)/docs/README_UTILS $(topdir)/docs/TODO $(topdir)/docs/WHATSNEW


## FIXME: Move this one to a ./configure --enable-win32-console
## Uncomment this line for  no-console mode on Windows.
## AM_LDFLAGS = -Wl,--subsystem,windows

## FIXME: Check that autofoo is doing its job and then remove this.
## Uncomment this line to compile on Solaris.
## AM_LIBS = -lresolv
