CXX=g++
CC=gcc
LD=g++
CXXFLAGS=$(CFLAGS)
CFLAGS=-c -Wall
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
