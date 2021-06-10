CC = g++
CPPFLAG = -Wall -g -std=c++11
LIB = -lpthread
TARGET = $(patsubst %.cpp, %.out, $(wildcard *.cpp))
HEADER = $(wildcard headers/*.h)

%.out : %.cpp $(HEADER)
	$(CC) $(CPPFLAG)  $< -o $@ $(LIB)

.PHONY : all clean

all : $(TARGET)

clean : 
	rm -f *.out

