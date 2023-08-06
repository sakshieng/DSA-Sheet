#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// by stacks with TC O(n) we can find next greater element 


// NEXT GREATER ELEMENT
/*
4 5 2 25 7 8
NGE:5 25 25 -1 8 -1
for 4 execute loop from 5 to 8 then fing greater 
for 5 execute loop from 2 to 8 but TC will be O(n^2)

after traversal the elements which remain in stack have no next greater element as they aren't popped :: -1 for them
*/
// we are keeping index in code for easier approach
vector<int> NGE(vector<int> v)
{
    vector<int> nge(v.size());
    stack<int> st;
    // jab tak stack empty hot nhi tb tk next greater declare krycha tya index che and jb tk stack ka top current element chya motha ahe
    for(int i=0;i<v.size();++i)
    {
        while(!st.empty() && v[i]>v[st.top()])
        {   
            // st.top() is index
            nge[st.top()] = i;
            st.pop();
        }
        // then push current element index
        st.push(i);
    }
    while(!st.empty())
    // means the elements which are reamined in stack
    {
        nge[st.top()] = -1;
        st.pop();
    }
    return nge;
}
int main()
{
   int n;
   cin>>n;
   vector<int> v(n);
//    vector input take
   for(int i=0;i<n;++i)
   {
     cin>> v[i];
   }
   vector<int> nge=NGE(v);
//    for printing array of NGE
for(int i=0;i<n;++i)
{
    // nge[i] have index which have nge of ith element and v[nge[i]] is value at that index
    if(nge[i] == -1)
    cout<< v[i]<<" "<< -1 <<endl;
    else
    cout<<v[i]<<" "<<v[nge[i]]<<endl;
}
cout<<endl;
   return 0;
}