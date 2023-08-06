#include <bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// defining a macro
#define M 5
// hierarchical inheritance
// array class is defined by third party then stack and queue are defined
class Array
{
protected:
    int arr[M];

public:
    Array();
    ~Array() {}
    void set(int d, int pos)
    {
        arr[pos] = d;
    }
    int get(int pos)
    {
        return arr[pos];
    }
};
Array::Array()
{
    for (int i = 0; i < M; i++)
    {
        arr[i] = 0;
    }
}
class Stack : public Array
{
    int top;

public:
    Stack() : Array()
    {
        top = -1;
    }
    ~Stack() {}
    int isFull()
    {
        return (top == M - 1);
    }
    int isEmpty()
    {
        return (top == -1);
    }
    // as pos to be inserted is top and it is incremented by +1
    void push(int d)
    {
        if (isFull())
            cout << "\nOverflow";
        else
            set(d, ++top);
        // arr[++top] = d
    }
    void pop()
    {
        if (isEmpty())
            cout << "\nUnderflow";
        else
            top--;
    }
    void display();
    void menu();
};
class Queue : public Array
{
    int fr, rr;

public:
    Queue() : Array()
    {
        rr = -1;
        fr = 0;
    }
    ~Queue() {}
    int isFull()
    {
        return (rr = M - 1);
    }
    int isEmpty()
    {
        return (rr < fr);
    }
    void insert(int d)
    {
        if (isFull())
            cout << "\nOverflow";
        else
        {
            set(d, ++rr);
        }
    }
    void remQue()
    {
        if (isEmpty())
            cout << "\nUnderflow";
        else
            fr++;
    }
    void display();
    void menu();
};
void Queue::display()
{
    if (isEmpty())
        cout << "\nEmpty queue";
    else
    {
        cout << "\nQueue data\n";
        for (int i = 0; i <= rr; i++)
        {
            cout<<" "<<arr[i];
        }
    }
}
    // parent class mdhe astana child class cha member access nhi krta yet
 void Queue::menu()
{
    int opt, d;
    while (1)
    {
        cout << "\nQueue menu\n1.Insert\n2.Remove\n3.Display\n4.Exit\nOption: ";
        cin >> opt;
        if (opt > 3)
            break;
        switch (opt)
        {
        case 1:
            cout << "\nData: ";
            cin >> d;
            insert(d);
            break;
        case 2:
            remQue();
            break;
        case 3:
            display();
            break;
        }
    }
}
void Stack::display()
{
    if (isEmpty())
        cout << "\nEmpty stack ";
    else
    {
        cout << "\nStack data\n";
        for (int i = top; i >= 0; i++)
        {
            cout << " " << get(i);
            // cout <<" "<<arr[i];
        }
    }
}
void Stack::menu()
{
    int opt, d;
    while (1)
    {
        cout << "\nStack menu\n1.push\n2.pop\n3.display\n4.exit\nOption:";
        cin >> opt;
        if (opt > 3)
            break;
        switch (opt)
        {
        case 1:
            cout << "\nData: ";
            cin >> d;
            push(d);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        }
    }
}
int main()
{
    cout<<"\nData structures\n1.stack\n2.Queue\n3.Choice: ";
    int opt;
    cin>>opt;
    if(opt<1 || opt>2)
        return 0;
    if(opt == 1)    
    {
        Stack s;
        s.menu();
    }
    else
    {
        Queue q;
        q.menu();
    }
    return 0;
}
