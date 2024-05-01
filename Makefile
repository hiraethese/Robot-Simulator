#
# Authors:
# Baturov Illia (xbatur00@stud.fit.vutbr.cz)
# Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
#
# Project:
# ICP-2024
#

ifeq ($(OS),Windows_NT)
    # Windows commands and settings
    CC=g++
    ICP_EXE = icp2024.exe
    RM = del /Q
    MKDIR = mkdir
    ZIP = zip
    QMAKE = qmake
    MAKE = mingw32-make
    RM_FLAGS = /F
    DIR_SEPARATOR = \\
else
    # Linux commands and settings
    CC=g++
    ICP_EXE = icp2024
    RM = rm -f
    MKDIR = mkdir -p
    ZIP = zip -r
    QMAKE = qmake
    MAKE = make
    RM_FLAGS =
    DIR_SEPARATOR = /
endif

# Phony targets
.PHONY: all clean q_prepare run doxygen pack

all: clean q_prepare
	$(MAKE) CXX=$(CC) -C src

q_prepare:
	$(QMAKE) -o src/Makefile icp2024.pro

run:
	./bin/$(ICP_EXE)

clean: clean_pack
	$(RM) obj/* moc/* bin/* src/qrc_icons.cpp src/ui_MainWindow.h src/Makefile src/.qmake.stash
	$(RM) -rf logs doc/html doc/latex

clean_pack:
	$(RM) xbatur00-xkukht01.zip

doxygen:
	doxygen doc/Doxyfile

pack: clean
	$(ZIP) xbatur00_xkukht01.zip src bin obj moc LICENSE Makefile README.txt icp2024.pro examples doc/Doxyfile
