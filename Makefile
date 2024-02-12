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
	qmake -o src/Makefile sim_robots.pro

run:
	./src/sim_robots

clean: clean_pack
	rm -f src/sim_robots src/*.o src/moc_mainwindow.cpp src/moc_predefs.h src/ui_mainwindow.h src/Makefile src/.qmake.stash
	rm -rf logs

clean_pack:
	rm -f xbatur00_xkukht01.zip

doxygen:
	echo man

pack: clean
	zip -r xbatur00_xkukht01.zip src LICENSE Makefile README.txt sim_robots.pro doc/Doxyfile examples