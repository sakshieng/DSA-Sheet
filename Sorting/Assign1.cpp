#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
// Write a method to merge B into A in sorted order.
void mergeArrays(int arr1[], int arr2[], int n1,int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    while (i < n1)
        arr3[k++] = arr1[i++];

    while (j < n2)
        arr3[k++] = arr2[j++];
}

int main()
{
    int n1, n2;
    cout<<"Enter n1 ";
    cin >> n1;
    cout<<"Enter n2 ";
    cin>>n2;

    int arr1[n1];
    int arr2[n2];
    cout << "Original array 1 ";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    cout << endl;
    cout << "Original array 2 ";
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    int arr3[n1];//as n1>n2
    mergeArrays(arr1,arr2, n1, n2,arr3);
    cout << endl;
    cout << "Sorted array: ";
    for (int i = 0; i < n1+n2; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;
    return 0;
}