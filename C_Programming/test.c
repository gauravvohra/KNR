
/*n example: This program will fail to compile because the 
 *  preprocessor will change the FALSE to 1 on the enum statement....
 *   *
 *    ****************************************************************************/

#include <stdio.h>
int main(void)
{
   signed char   cs = -1;
    unsigned char cu = cs;

    signed int   is = -1;
    unsigned int iu = is;

    if (is == iu)     printf("equal\n");
    else              printf("not equal\n");

    if (cs == cu)     printf("equal\n");
    else              printf("not equal\n");

return 0;
}
