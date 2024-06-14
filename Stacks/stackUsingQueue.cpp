#include <bits/stdc++.h>
using namespace std;
class Stack
{
    // Define the data members.
private:
    queue<int> q1;
    queue<int> q2;
    int length;

public:
    Stack()
    {
        // constructor
        length = 0;
    }

    int getSize()
    {
        return length;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    void push(int element)
    {
        q2.push(element);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.swap(q2);
        length++;
    }

    int pop()
    {
        if (!q1.empty())
        {
            int value = q1.front();
            q1.pop();
            length--;
            return value;
        }
        return -1;
    }

    int top()
    {
        if (!q1.empty())
        {
            return q1.front();
        }
        return -1;
    }
};
int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl;

    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    if (stack.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    cout << "Stack size: " << stack.getSize() << endl;
    return 0;
}

// pop O(N) push O(1)
class Queue
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    Queue() {}
    void push(int x)
    {
        q1.push(x);
    }
    int pop()
    {
        if (q1.empty())
            return -1;
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int tmp = q1.front();
        q1.pop();
        q1.swap(q2);
        return tmp;
    }
};
// push O(n) pop O(1)
class Queue1
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    Queue1() {}
    void push(int x)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    int pop()
    {
        if (q1.empty())
            return -1;
        int tmp = q1.front();
        q1.pop();
        return tmp;
    }
};