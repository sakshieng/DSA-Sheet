#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
class node
{
 private:
        int data;
        node *next;
 public:
        node(){};
        node *print_list(node *n);        
};
void print_list(node *n)
{
    while(n->next != NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
    cout<<endl;
}
int main()
{
   
   return 0;
}