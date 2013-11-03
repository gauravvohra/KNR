#include<stdio.h>

#define IN  1
#define OUT 0

int main()
{
	int nw, nc ;
	int c ;
	int state = OUT ;

	nc = nw = 0 ;
	
	while ((c = getchar()) != 'A') {
		if(c == ' '|| c == '\t'|| c == '\n')
			state = OUT ;
		else if(state == OUT)
		{
			state = IN ;
			nw++;
		}
	nc++ ;
	
	}

	printf(" The nc %d nw  %d \n ",nc,nw);
	return 0;

}

