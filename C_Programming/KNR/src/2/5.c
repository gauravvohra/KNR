#include "common.h"

int any(char * , char *);

int main()
{
	char s1[10], s2[10] ;
	
	int pos = -1 ;
	
	printf(" Enter String 1 \n") ;
	scanf("%s", s1);
	
	printf(" Enter String 2 \n") ;
	scanf("%s",s2);

	pos = any(s1,s2) ;
	
	printf(" The value of pos %d \n",pos);	
	return 0 ;
}

int any (char *s1 , char *s2)
{
	int pos = -1 ;
	char *temp = s2 ;
	while((*(s1))) {
		printf("1: s1 %c s2 %c \n",*s1,*s2);
		pos++ ;
		printf("Value of pos %d \n", pos);
		s2 = temp ;
		while((*(s2))) {
				printf("2: s1 %c s2 %c \n",*s1,*s2);
				if(*s1 == *s2) {
				printf("Value found at pos %d \n", pos);
				return pos ;
				}
				s2++;
			 }s1++;

		}
		pos = -1 ;
		return pos ;
}		

