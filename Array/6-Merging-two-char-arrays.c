/* Merging:
Add two character type arrays.
*/

#include <stdio.h>
#include<string.h>

void mergeStr(char *str1, char *str2)
{
    int len = strlen(str1), i=0;
    while(str2[i] != '\0'){
        str1[len] = str2[i];
        len++;
        i++;
    }
    str1[len] = '\0';
}

int main()
{
    int x, m, n, i, k;
    char str1[50], str2[50], merge[100];

    printf(" Enter your 1st String: ");
    gets(str1);

    printf("\n Enter your 2nd String: ");
    gets(str2);

    printf("\n\n 1st String: ");
    puts(str1);

    printf("\n\n 2nd String: ");
    puts(str2);

    printf("\n\n Merged String: ");
    mergeStr(str1, str2);
    puts(str1);
    return 0;
}
