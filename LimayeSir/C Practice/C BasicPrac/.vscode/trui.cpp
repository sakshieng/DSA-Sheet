#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    if(n%4==0 && n>=4)
	    cout<<n<<endl;
	    else
	    if(n%4==1 && n>4)
	    cout<<n-1<<endl;
	    else
	    if(n%4==2 && n>4)
	    cout<<n-1<<endl;
	    else
	    if(n%4==3 && n>4)
	    cout<<n-1<<endl;
	    else
	    if(n<4)
	    cout<<n<<endl;
	}
	return 0;
}
