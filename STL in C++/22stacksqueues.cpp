#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// recursion uses stacks(LIFO)-->opn genrally on top element and size -->use of s.top()
// queues(FIFO) -->use of q.front()
// write q.pop() ans s.pop() for both



// BALANCED PARENTHESIS
// https://www.hackerrank.com/challenges/balanced-brackets/problem

unordered_map<char,int> symbols={{'[',-1},{'(',-2},{'{',-3},{']',1},{')',2},{'}',3}};
// keep opening bracket -1 and closing +1
string isBalanced(string s) {
   stack<char> st;
   for(char bracket:s)
   {
      if(symbols[bracket] < 0)
      {
         // means opening ::insert in stack
         st.push(bracket);
      }
      else
      {
         if(st.empty())
         return "NO";
         char top=st.top();
         st.pop();
         if(symbols[top] + symbols[bracket] != 0)
         return "NO";
      }
   }
   if(st.empty())
   return "YES";
   else
   return "NO";
}

int main()
{
   // opening bracket is recnetly closed by closed bracket 
   // for diff types of bracket ({[]}) stack pop up element should match with outside element
   int t;
   cin>>t;
   while(t--)
   {
      string s;
      cin >> s;
      cout<<isBalanced(s)<<endl;
   }
   return 0;
}