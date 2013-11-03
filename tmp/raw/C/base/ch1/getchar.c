#include<stdio.h>

int main()
{
	int nb, nt, nl, nc ;
	int c ;
	
	nb = nt = nl = nc = 0 ;
	
	while ((c = getchar()) != 'A') {
		if(c == ' ')
			nb++ ;
		else if(c == '\t')
			nt++ ;
		else if(c == '\n')
			nl++;
	nc++ ;
	}

	printf(" The nb %d nt %d nl %d nc %d \n " ,nb,nt,nl,nc);
	return 0;

}

