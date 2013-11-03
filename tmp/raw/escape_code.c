#include <stdio.h>

#define COLOR_RED "\033[;1;31m"
#define COLOR_END "\033[0m"

int main() {
    printf("%sHello World%s\n", COLOR_RED, COLOR_END);
    return 0;
}
