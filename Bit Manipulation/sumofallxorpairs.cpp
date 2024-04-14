#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Returns sum of bitwise OR of all pairs
    long long int sumXOR(int arr[], int n)
    {
        long long int sum=0;
    	for(int i=31;i>=0;i--)
    	{
    	    long long int set=0,nset=0;
    	    for(int j=0;j<n;j++)
    	    {
    	        if(arr[j]&(1<<i))
    	        {
    	            set++;
    	        }
    	        else
    	        {
    	            nset++;
    	        }
    	    }
    	    sum=sum+set*nset*pow(2,i);
    	}
    	
    	return sum;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

