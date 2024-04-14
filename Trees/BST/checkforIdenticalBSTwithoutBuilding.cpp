//https://www.codingninjas.com/studio/library/check-for-identical-bsts-without-building-the-trees 
//check for identical BSTs without building the trees
#include<bits/stdc++.h>
using namespace std;

bool checkBST(vector<int>arr1, vector<int>arr2)
{
    // Calculate size of both arrays
    int n = arr1.size();
    int m = arr2.size();
    
    // Check if size is different 
    if(n != m)
    return false;
    
    // Check if size is zero
    if(n == 0)
    return true;
    
    // Check for root node
    if(arr1[0] == arr2[0])
    {
        vector<int>array_left1;
        vector<int>array_right1;
        vector<int>array_left2;
        vector<int>array_right2;
        
        for(int i=1;i<n;i++)
        {
            
            // Adding elements in left subtree of arr1
            if(arr1[i] < arr1[0])
            array_left1.push_back(arr1[i]);
            
            // Adding elements in left subtree of arr1
            else
            array_right1.push_back(arr1[i]);
            
            // Adding elements in left subtree of arr2
            if(arr2[i] < arr2[0])
            array_left2.push_back(arr2[i]);
            
            // Adding elements in left subtree of arr2
            else
            array_right2.push_back(arr2[i]);
        }
        
        bool left = checkBST(array_left1, array_left2);
        bool right = checkBST(array_right1, array_right2);
        
        return left && right;
    }
    
    // If all conditions are false then return false
    return false;
}

int main()
{
    // Declaring two arrays 
vector<int>arr1;
vector<int>arr2;

// Calculate the size of both arrays 
int n,m;
cout<<"Enter size of arrays : ";
cin>>n>>m;

cout<<"Enter elements of array 1 - ";
for(int i=0;i<n;i++)
{
    int x;
    cin>>x;
    arr1.push_back(x);
}

cout<<"Enter elements of array 2 - ";
for(int i=0;i<m;i++)
{
    int x;
    cin>>x;
    arr2.push_back(x);
}

// Check is size of arrays is different 
if(n != m)
{
    cout << "No, Arrays are not identical";
    exit(0);
}

if(checkBST(arr1, arr2))
cout << "Yes, Arrays are identical";

else
cout << "No, Arrays are not identical";

return 0;
}