#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OUT 1
#define IN  0 

void reverse_string(char *);
void reverse_words(char *);
int main()
{
	char string[] ="MY NAME GAURAV " ;
	
	reverse_words(string);
	
	return 0 ;

}

void reverse_words(char *string)
{
	char *buffer = NULL;
	buffer = malloc(sizeof(char) * 20); 
	printf("buffer size %d\n",sizeof(buffer));
	int size_buffer = 0 ;
	int pos = 0 ;
	int i = 0 ;	
	
	while(*string) {
	pos = i + pos ;
	while( (*string) != ' ') {
		*buffer++ = *(string++) ; 		
		size_buffer++;
		}
	//*buffer = '\0' ;
	printf("buffer size %d\n",size_buffer);
	size_buffer--;
	for(i = pos ; i < size_buffer+pos ; i++,size_buffer--){
                buffer[i]^= buffer[(size_buffer)+pos ];
                buffer[(size_buffer)+pos]^= buffer[i];
                buffer[i] ^= buffer[(size_buffer)+pos];
        }
		printf("1: String after reversal %s\n", buffer);

		string++;
	pos++;
}
printf("String after reversal %s\n", buffer);
}

// Reverses String without using third variable
 
void reverse_string(char *string)
{
	int size = strlen(string)-1 ;
	int i = 0;	
	
	for(i=0 ; i < size ; i++, size--){
		string[i]^= string[size];
		string[size]^= string[i];
		string[i] ^= string[size]; 
	}
	printf("String after reversal %s\n", string);
}

