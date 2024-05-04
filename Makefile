#
# Authors:
# Baturov Illia (xbatur00@stud.fit.vutbr.cz)
# Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
#
# Project:
# ICP-2024
#
ifeq ($(OS),Windows_NT)
    RM_FILE=del /S /Q
    RM_DIR=rmdir /S /Q
    TRG_BIN=bin\icp2024.exe
	ZIP_MAKER=tar.exe acvf
	DIR_SEPARATOR=\\
else
    RM_FILE=rm -f
    RM_DIR=rm -rf
    TRG_BIN=bin/icp2024
	ZIP_MAKER=zip -r
	DIR_SEPARATOR=/
endif

# Phony targets
.PHONY: all clean q_prepare run doxygen pack

all: q_prepare
	make -C src

q_prepare:
	qmake -o src$(DIR_SEPARATOR)Makefile icp2024.pro

run:
	./$(TRG_BIN)

clean:
	$(RM_FILE) src$(DIR_SEPARATOR)qrc_icons.cpp src$(DIR_SEPARATOR)ui_MainWindow.h src$(DIR_SEPARATOR)Makefile src$(DIR_SEPARATOR)Makefile.Debug src$(DIR_SEPARATOR)Makefile.Release src$(DIR_SEPARATOR).qmake.stash
	$(RM_DIR) src$(DIR_SEPARATOR)release src$(DIR_SEPARATOR)debug obj moc  bin

doxygen:
	doxygen doc/Doxyfile

pack:
	$(ZIP_MAKER) xbatur00-xkukht01.zip src res LICENSE Makefile README.txt icp2024.pro examples doc$(DIR_SEPARATOR)Doxyfile

