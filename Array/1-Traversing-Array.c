/* Traversing: carry out the following operations on an Array
a) Maximum Value b) Minimum Value c) Average Value d) Total Value e) Sin Value
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void printArray(int arr[], int n);
int maximumValue(int arr[], int n);
int minimumValue(int arr[], int n);
float avgValue(int arr[], int n);
int totalValue(int arr[], int n);
void sinValue(int arr[], int n);

int main()
{
    int array[100], n, i;
    printf("Enter the total number of elements: ");
    scanf("%d", &n);

    printf("\nEnter %d number of element: ", n);
    for(i = 0; i<n; i++){
        scanf("%d", &array[i]);
    }

    printf("\n Maximum Value: %d \n", maximumValue(array, n));
    printf("\n Minimum Value: %d \n", minimumValue(array, n));
    printf("\n Average Value: %.2f \n", avgValue(array, n));
    printf("\n Total value: %d \n", totalValue(array, n));
    sinValue(array, n);
    return 0;
}

int maximumValue(int arr[], int n)
{
    int max = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int minimumValue(int arr[], int n)
{
    int min= arr[0], i;
    for(i=0; i<n; i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}

int totalValue(int arr[], int n)
{
    int total=0;
    for(int i=0; i<n; i++){
        total = total + arr[i];
    }
    return total;
}

float avgValue(int arr[], int n)
{
    float avg, sum=0;
    int i;
    sum = totalValue(arr, n);
    avg = (sum/n);
    return avg;
}

void sinValue(int arr[], int n)
{
    printf("\n Sin Values: \n");
    for(int i=0; i<n; i++){
        printf("   Sin(%d) = %.2f  \n",arr[i], sin(arr[i]));
    }
}
