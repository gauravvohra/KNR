all:
	gcc -Wall -o bin/list src/list.c -I inc 

format:	
	indent -nut -kr src/*c inc/*h
	rm src/*~ inc/*~ bin/*
 
debug:  
	gcc -Wall -g -o bin/list.dbg  src/list.c -I inc
