#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *str1 = malloc(4 * sizeof(char));
    char *str2 = malloc(4 * sizeof(char));

    str1[0] = 'H';
    str1[1] = 'e';
    str1[2] = 'y';
    str1[3] = '\0';

    str2[0] = 'H';
    str2[1] = 'o';
    str2[2] = 'i';
    str2[3] = '\0';

    printf("String 1 is %s \n", str1);
    printf("String 2 is %s \n", str2);

    // Swap arrays:
    char *tmp;
    tmp = str1; 
    str1 = str2;
    str2 = tmp;

    printf("String 1 is %s \n", str1);
    printf("String 2 is %s \n", str2);

    return 0;
}