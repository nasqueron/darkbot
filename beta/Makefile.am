## Top level Makefile.am
## by ron <ron@darkbot.org>

EXTRA_DIST = scripts/* docs/* dat/* source/langs/* Makefile source/Makefile
SUBDIRS = source
DIST_SUBDIRS = source 

all-am: source/darkbot$(EXEEXT)
	cp -f source/darkbot$(EXEEXT) .
	
convertdb: source/convertdb$(EXEEXT)
	cp -f source/convertdb$(EXEEXT) .

install-exec-local:
	$(INSTALL) -d -m 755 $(prefix)
	$(INSTALL) -m 744 ./source/darkbot $(prefix)
	@echo 
	@echo darkbot-`cat VERSION` has been installed to $(prefix)
	@echo


