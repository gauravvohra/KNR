#include "common.h"

void ll_create (struct node *llf)
{
	int val = 0 ;

 	llf = malloc(sizeof(struct node *));
	printf(" Node Created \n" ) ;
	printf(" Enter the value to be stored \n");
	scanf(" %d \n", val );
	llf->data = val;
	llf->next = NULL ;



int main()
{
	int choice = 0; 
	struct node *ll = NULL ;

	printf(" Menu : Enter the operation on Linked List \n ") ;
	printf(" 1. Create  \n ") ;
	scanf(" %d \n", choice);
	
	switch(choice)
	{
		case 1 :
			printf(" You have choosen to Create a Linked List \n");
			ll_create(ll);
			break ;
		

			
	return 0 ;
}
