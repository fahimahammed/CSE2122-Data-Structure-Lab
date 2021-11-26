/*Sort 10 integer data using Quick-Sort algorithm.
*/

#include<stdio.h>

void decode(int *a, int n)
{
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
}

void quicksort(int *a, int f, int l)
{
    int temp, i=f, j=l, p= a[(f+l)/2];

    while(i<=j){
        while(a[i] < p) i++;
        while(a[j] > p) j--;

        if(i<=j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if(f<j){
        quicksort(a, f, j);
    }
    if(l>i){
        quicksort(a, i, l);
    }
}

int main()
{
    int a[] = {2, 5, 1, 6, 3, 4};
    quicksort(a, 0, 5);
    decode(a, 6);
}
