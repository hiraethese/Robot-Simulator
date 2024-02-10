CC = g++
CFLAGS = -Wall -Wextra -std=c++17 -O3
TARGET = sim_robots

SRCDIR = .
GUIDIR = gui
COREDIR = core

SOURCES = $(wildcard $(SRCDIR)/*.cpp) \
          $(wildcard $(GUIDIR)/*.cpp) \
          $(wildcard $(COREDIR)/*.cpp)

HEADERS = $(wildcard $(SRCDIR)/*.h) \
          $(wildcard $(GUIDIR)/*.h) \
          $(wildcard $(COREDIR)/*.h)

OBJECTS = $(SOURCES:.cpp=.o)

all: qmake-build

qmake-build: $(TARGET).pro
	qmake -o Makefile $(TARGET).pro
	$(MAKE) -f Makefile

# Правило для компиляции .cpp в .o
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
	rm -f Makefile
