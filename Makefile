#
# Authors:
# Baturov Illia (xbatur00@stud.fit.vutbr.cz)
# Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
#
# Project:
# ICP-2024
#

all: clean q_prepare
	make -C src

q_prepare:
	qmake -o src/Makefile icp2024.pro

run:
	./bin/icp2024

clean:
	rm -f src/icp2024 src/qrc_icons.cpp src/ui_MainWindow.h src/Makefile src/.qmake.stash
	rm -rf obj moc bin

clean_pack:
	rm -f xbatur00-xkukht01.zip

doxygen:
	doxygen doc/Doxyfile

pack:  clean_pack clean
	zip -r xbatur00-xkukht01.zip src LICENSE Makefile README.txt icp2024.pro examples res doc/Doxyfile
