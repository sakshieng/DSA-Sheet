#include <bits/stdc++.h>
/* Sakshi */
using namespace std;

void merge(int *arr, int start, int end)
{
    int mid = start + end / 2;
}
void mergeSort(int *arr, int start, int end)
{
    int mid = start + end / 2;
    // base case condition
    if (start > end)
    {
        return;
    }
    // left part sorting
    mergeSort(arr, start, mid);
    // right part sort
    mergeSort(arr, mid + 1, end);
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}