CXX=g++
CC=gcc
LD=g++
CXXFLAGS=$(CFLAGS) -std=c++11
CFLAGS=-c -Wall -Werror -O3
LDFLAGS=
CXXSOURCES=main.cpp doalg.cpp
CSOURCES=COMPARE.c 
CXXOBJECTS=$(CXXSOURCES:.cpp=.o)
COBJECTS=$(CSOURCES:.c=.o)
OBJECTS=$(COBJECTS) $(CXXOBJECTS)
EXECUTABLE=doalg

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm *.o $(EXECUTABLE)
