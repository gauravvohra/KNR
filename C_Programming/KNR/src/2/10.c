#include "common.h"

int main()
{
    int ch = 0;
    printf(" Enter a Character Value \n");
    ch = getchar();
    printf(" Character Uppercase : %c \n", ch);
    ch = lower(ch);
    printf(" Character Lowercase : %c \n", ch);
    return 0;

}

int lower(int a)
{
    (a >= 'A' && a <= 'Z') ? a = (a + 'a' - 'A') : a;
    return a;
}
