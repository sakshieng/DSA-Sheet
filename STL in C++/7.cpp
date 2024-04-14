#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// vector of vectors
// it is basically 2d array which have fixed no of rows and have dynamic no of columns
// by push back and pop back we can change no of rows to dynamic
// here v[0] is vector
void printVec(vector<int> &v)
{
    cout<<"size:"<<v.size()<<endl;
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int N;
    cin>>N;
    vector<vector<int>>v;
    for(int i=0;i<N;i++)
    {
    int n;
    cin>>n;
    v.push_back(vector<int>());
    // we have created empty vector here and then is is accesed further
    for(int j=0;j<N;++j)
    {
        int x;
        cin>>x;
        v[i].push_back(x);
    }
    }
    for(int i=0;i<v.size();++i)
    {
        printVec(v[i]);
    }  
    cout<<v[0][1];
    // 0th vector ka 1st element
}
