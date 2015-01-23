CC=g++
CFLAGS=-I. -std=c++11 
DEPS = data.hpp

%: %.cpp $(DEPS)
		$(CC) -o $@ $< $(CFLAGS)

all: test1
