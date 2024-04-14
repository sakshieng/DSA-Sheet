#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long int n;
	    cin>>n;
	    if(n%2==0)
	    {
	        int m=n/2;
	        cout<<m*n<<endl;
	    }
	    else
	    {
	        int k=(n+1)/2;
	       // cout<<k<<endl;
	        int j=k*n;
	        cout<<j-k<<endl;
	    }
	}
	return 0;
}
