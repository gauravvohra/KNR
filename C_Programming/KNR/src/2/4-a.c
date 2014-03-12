#include <stdio.h>

void squeeze(char * , char *);

int main()
{
	char s1[10], s2[10] ;
	
	int pos = -1 ;
	
	printf(" Enter String 1 \n") ;
	scanf("%s", s1);
	
	printf(" Enter String 2 \n") ;
	scanf("%s",s2);

	squeeze(s1,s2) ;
	
	return 0 ;
}

void squeeze (char *s1 , char *s2)
{
int i,j,k;
// loop checks for non occuring characters in string 2 and then assigns to k incrementation
	for (i = k = 0; s1[i] != '\0'; i++){
		for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
			;
		if (s2[j] == '\0')
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
	printf("\n modified string : %s\n",s1);
	
}		

