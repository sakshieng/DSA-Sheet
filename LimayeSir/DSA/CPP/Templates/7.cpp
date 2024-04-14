#include <bits/stdc++.h>
#define M 5
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
template <class T>
class Stack
{
    T var[M];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    void push(T a)
    {
        if (top == M - 1)
        {
            cout << "\nOverflow";
        }
        else
        {
            top++;
            var[top] = a;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "\nUnderflow";
        }
        else
        {
            top--;
        }
    }
    void display();
    void menu();
};
template <class T>
void Stack<T>::display()
{
    if (top == -1)
    {
        cout << "\nEmpty stack";
    }
    else
    {
        cout << "\nData:\n";
        for (int i = top; i >= 0; i--)
            cout << var[i] << " ";
    }
}
template <class T>
void Stack<T>::menu()
{
    T val;
    int opt;
    while (1)
    {
        cout << "\nStack\n1.Push\n2.Pop\n3.Display\n4.Exit\nOption: ";
        cin >> opt;
        if (opt > 3)
            break;
        switch (opt)
        {
        case 1:
            cout << "\nData: ";
            cin >> val;
            push(val);
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
    Stack<int>a;
    a.menu();
    return 0;
}