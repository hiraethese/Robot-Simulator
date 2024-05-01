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
    RM = del /Q
    MKDIR = mkdir
    ZIP = zip
    QMAKE = qmake
    MAKE = mingw32-make
    RM_FLAGS = /F
    DIR_SEPARATOR = \\
else
    # Linux commands and settings
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
	$(MAKE) -C src

q_prepare:
	$(QMAKE) -o src/Makefile icp2024.pro

run:
	./bin/icp2024

clean: clean_pack
	$(RM) src/icp2024 obj/* moc/* bin/* src/qrc_icons.cpp src/ui_MainWindow.h src/Makefile src/.qmake.stash
	$(RM) -rf logs doc/html doc/latex

clean_pack:
	echo $(RM)
	$(RM) xbatur00_xkukht01.zip

doxygen:
	doxygen doc/Doxyfile

pack: clean
	$(ZIP) xbatur00_xkukht01.zip src bin obj moc LICENSE Makefile README.txt icp2024.pro examples doc/Doxyfile
