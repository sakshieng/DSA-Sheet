 // 8) Write a program in C to print the array elements using recursion
 //2 parameters array and size of array
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
void printArray(int arr[], int start, int len);
int main()
{
    int arr[MAX_SIZE];
    int N, i;
    system("cls");
    printf("Enter size of the array: ");
    scanf("%d", &N);
    printf("Enter elements in the array: ");
    for(i=0; i<N; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Elements in the array: ");
    printArray(arr, 0, N);
    return 0;
}
void printArray(int arr[], int start, int len)
{
    if(start >= len)
        return;
    printf("%d, ", arr[start]);
    printArray(arr, start + 1, len); 
}