/*Merging:
Add two integer type arrays.
*/

#include<stdio.h>

int main()
{
    int x, m, n, i, k;
    printf(" Enter 1st array size: ");
    scanf("%d", &m);
    printf("\n Enter 2nd array size: ");
    scanf("%d", &n);

    x = m+n;
    int array1[m], array2[n], merge[x];

    printf("\n Enter 1st array elements : ");
    for(i = 0; i<m; i++){
        scanf("%d", &array1[i]);
        merge[i] = array1[i];
    }

    k = m;
    printf("\n Enter 2nd array elements : ");
    for(i = 0; i<n; i++){
        scanf("%d", &array2[i]);
        merge[k] = array2[i];
        k++;
    }

    printf("\n 1st array elements: ");
    for(i=0; i<m; i++){
        printf("%d  ", array1[i]);
    }

    printf("\n\n 2nd array elements: ");
    for(i=0; i<n; i++){
        printf("%d  ", array2[i]);
    }

    printf("\n\n Merged array elements: ");
    for(i=0; i<x; i++){
        printf("%d  ", merge[i]);
    }
    printf("\n");
    return 0;
}
