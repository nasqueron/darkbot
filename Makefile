# ------------------------------------------------ #
# Darkbot Makefile (c) Jason Hamilton 07.06.98     #
# paul@msunix.co.uk 08/12/2001                     #
# ------------------------------------------------ #
# To compile Darkbot, just type 'make'             #
# To compile for Win32 (95/98/NT) 'make win'       #
# To compile for Win32 with no console, type       #
# 'make win2'                                      #
#                                                  #
# To compile in debug mode, type 'make debug'      #
# To compile and have all data be logged to        #
# ..darkbot_debug.log, 'make debug2'               #
# ------------------------------------------------ #

SOURCE_DIR = source

all:
	@cd ${SOURCE_DIR}; make all; cd ..;

win:
	@cd ${SOURCE_DIR}; make win; cd ..;

win2:
	@cd ${SOURCE_DIR}; make win2; cd ..;

debug:
	@cd ${SOURCE_DIR}; make debug; cd ..;

debug2:
	@cd ${SOURCE_DIR}; make debug2; cd ..;

clean:
	@echo "Cleaning ..."; cd ${SOURCE_DIR}; make clean; cd ..;
