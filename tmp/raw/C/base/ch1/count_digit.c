#include<stdio.h>

#define NO_OF_DIGITS 10

int main()
{
	int c, i, ns ;
	int a[NO_OF_DIGITS] ; 
	ns = 0 ;

	for( i=0 ; i < NO_OF_DIGITS ; i++)
		a[i] = 0 ;

	while ((c = getchar()) != 'A') {
		if(c == ' '|| c == '\t'|| c == '\n')
			ns++;
		else
			++a[c- '0'] ;
	}
		

	for( i=0 ; i < NO_OF_DIGITS ; i++)
		printf(" Numerical values %d \n ", a[i]);

		printf(" The ns %d \n " ,ns);
	
		return 0;

}

