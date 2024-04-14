#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(){};
    node(int val)
    {
        data=val;
        next=NULL;
    }
    void display();
    void insert(int data);
};
void node::display()
{
    if(!next) return;
    node *Node;
    if(Node->next != NULL)
    {
        cout<<Node->data<<" ";
        Node=Node->next;
    }
    cout<<endl;
}
void node::insert(int data)
{
    
}
int main()
{
   
   return 0;
}