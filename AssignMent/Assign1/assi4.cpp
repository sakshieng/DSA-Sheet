#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool issuperPrime(int n)
{
    if(n<=1) return false;
    for (int i = 2; i < n; i++)
    {
        if(n%i == 0)
            return false;
        return true;
    }
}

int main()
{
    int n;
    cout<<"Enter your number:\n";
    cin>>n;
    int tmp=n;
    // declare flag as true 
    bool flag=true;
    if(issuperPrime(n))
    {
        while(n)
        {
            int k=n%10;
            if (issuperPrime(k))
            {
                flag=false;
                break;
            }
            n/=10;
        }
    }
    n=tmp;
    if(flag == true)
    {
        cout<<n<<" is superprime\n"<<"\n";
    }
    else
    {
        cout<<n<<" is not superprime\n"<<"\n";
    }
}
