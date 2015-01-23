CC=g++
CFLAGS=-I. -std=c++11 
DEPS = 

%: %.cpp $(DEPS)
		$(CC) -o $@ $< $(CFLAGS)

all: test1
