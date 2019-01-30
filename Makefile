all: Student

CC= g++

CCFLAGS= -std=c++14

CCFLAGS1=-c -Wall

Student: start1.o
		 $(CC) start1.o -o Student

start1.o: start1.cpp start1.h
		  $(CC) $(CCFLAGS) $(CCFLAGS1) start1.cpp start1.h

clean:
		  rm -rf *o Student
