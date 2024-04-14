#include<iostream>
#include "stackimplement.h"
using namespace std;
class Stack
{
    NODE *top;
public:
    Stack()
    {
        top=NULL;
    }
    ~Stack(){};
    void push(int d)
    {
        top=new NODE(d,top);
    }
    void pop()
    {
        if(top==NULL)
            cout<<"\nUnderflow";
        else
        {
            NODE *a=top;
            top=a->getNext();
            delete a;
        }
    }
    void display();
    void menu();
};
Stack::~Stack()
{
    NODE *a=top;
    while(top!=NULL)
    {
        // top=top->getNext; we cant write like this becauz a pointer to a bound function may only be used to call the function
        top=top->getNext();
        delete a;
        a=top;
    }
}
void Stack::display()
{
    NODE *a=top;
    if(top==NULL)
        cout<<"\nEmpty stack";
    else
    {
        cout<<"\nData\n";
        while(a!=NULL)
        {
            cout<<" "<<a->getData();
            a=a->getNext();
        }
    }
}
void Stack::menu()
{
    int opt,d;
    while(1)
    {
        cout<<"\nMenu\n1.Push\n2.Pop\n3.Display\n4.Exit\n5.option:";
        cin>>opt;
        if(opt>3)
            break;
        switch(opt)
        {
        case 1:
            cout<<"\nData";
            cin>>d;
            push(d);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
        }
    }
}
int main()
{
    Stack s;
    s.menu();
    return 0;
}