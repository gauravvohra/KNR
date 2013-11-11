NUMBERS = 10

all:
	$(foreach var,$(NUMBERS),gcc -Wall -o bin/2/$(var) src/2/$(var).c -I inc/2/;)

format:	
	$(foreach var,$(NUMBERS),indent -nut -kr src/2/*c inc/2/*h;)
	rm src/2/*~ inc/2/*~ bin/2/*
 
debug:  
	gcc -Wall -g -o bin/list.dbg  src/list.c -I inc
