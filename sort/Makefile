CC=gcc
CFLAGS=
CXX=g++
INC=

all: run

sortpp: sort.cpp
	g++ -o sortpp sort.cpp

#sort:sort.c 
#	echo $<
#	$(CC) $(INC) -o $@ $<
#
#sort_pp:sort.cpp
#	echo $<
#	$(CC) $(INC) -o $@ $<

run: sortpp
	./sortpp


clean:
	/bin/rm -rf sort sortpp

