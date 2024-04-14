#include <bits/stdc++.h>
#define M 5
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// implementation of stack
class Stack
{
public:
    int top;
    int arr[M];
    Stack()
    {
        top = -1;
    }
    ~Stack(){};
    void push(int t)
    {
        if (top == M - 1)
        {
            cout << "\nOverflow";
            return;
        }
        else
        {
            arr[top] = t;
            arr[top]++;
        }
    }
    void pop()
    {
        if (top == -1)
            cout << "Underflow";
        top--;
    }
    int isEmpty()
    {
        return top == -1; // otherwise 0 if empty then -1
    }
    int isFull()
    {
        return top == M - 1;
    }
    void display();
    void menu();
};
void Stack::display()
{
    if (isEmpty())
    {
        cout << "empty stack";
        return;
    }
    cout << "\nstack data\n";
    for (int i = M - 1; i > 0; i--)
    {
        cout << " " << arr[i];
    }
}
void Stack::menu()
{
    int opt, d;
    while (1)
    {
        cout << "\nMenu\n1.push\n2.pop\n3.empty\n4.full\nexit";
        cin >> opt;
        if (opt > 3)
            break;
        switch(opt)
            {
            case 1:
                cout << "Data";
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
// when we define func under class then it is inline func1
// othe func which has more complex(which has goto sta) will declare inside class and define outside class
int main()
{
    Stack s;
    s.menu();
    return 0;
}