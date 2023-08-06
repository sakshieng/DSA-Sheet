#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> st1;
    stack<int> st2;
    int size;

public:
    Queue() {
        size = 0;
    }

    void enQueue(int val) {
        // push elements from st1 to st2
        while (!st1.empty()) {
            int value = st1.top();
            st1.pop();
            st2.push(value);
        }
        // push the new element to st1
        st1.push(val);
        // push elements back from st2 to st1
        while (!st2.empty()) {
            int value = st2.top();
            st2.pop();
            st1.push(value);
        }
        size++; // increment size as an element is added
    }

    int deQueue() {
        if (st1.empty())
            return -1;
        else {
            int val = st1.top();
            st1.pop();
            size--;
            return val;
        }
    }

    int peek() {
        if (st1.empty())
            return -1;
        else {
            int val = st1.top();
            return val;
        }
    }

    bool isEmpty() {
        return st1.empty();
    }
};
int main() {
    Queue queue;

    queue.enQueue(10);
    queue.enQueue(20);
    queue.enQueue(30);

    cout << "Front element: " << queue.peek() << endl;

    cout << "Dequeued element: " << queue.deQueue() << endl;
    cout << "Dequeued element: " << queue.deQueue() << endl;

    if (queue.isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}
