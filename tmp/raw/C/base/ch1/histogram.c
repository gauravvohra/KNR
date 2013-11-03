#include<stdio.h>

#define IN  1
#define OUT 0
#define MAXWORDLENGTH 10

int main()
{
	int nw, nc, j, c, i = 0 ;
	int state = OUT ;
	int a[10] = { 0 };
	
	nc = nw = i = j = 0;

	while ((c = getchar()) != 'A'){
		if(c == ' '|| c == '\t'|| c == '\n'){
		if(nc <= MAXWORDLENGTH)
			a[nw-1] = nc ;
		else 
			a[MAXWORDLENGTH]++ ;
		
		state = OUT ;
		nc = 0 ;
		}
		else {
			if(state == OUT)
			{
				state = IN ;
				nw++;
			}
			nc++;
		}	
	}
	
	a[nw-1] = nc ;
	
/* Horizontal Histogram */

	for(i = 0 ; i < MAXWORDLENGTH ; i++){
		for(j = 0 ; j < nw ; j++)
			if(a[j]  == i )
				printf("* \t ");
		printf(" \n %d | ", i);
	}
	printf(" \n   +-----------------------------\n");
/*		
	for( i = 0;i < nw ;i++){
		printf(" \n ");
		for(j = 0; j < a[i] ; j++)
			printf(" - ");
		
		printf(" \n ");
	}
*/	
	return 0;

}

