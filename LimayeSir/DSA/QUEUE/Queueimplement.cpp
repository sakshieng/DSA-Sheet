#include <bits/stdc++.h>
#include "Queueimplement.h"
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
// Queue using Linked list
using namespace std;

class Queue
{
    NODE *fr, *rr;

public:
    Queue()
    {
        fr = rr = NULL;
    }
    ~Queue();
    void insert(int);
    void remque();
    void display();
    void menu();
};
void Queue::insert(int d)
{
    NODE *a = new NODE();
    if (fr == NULL)
    {
        fr = a;
    }
    else
    {
        rr->setNext(a);
        rr = a;
    }
}
void Queue::remque()
{
    if (fr == NULL) // Using LL so no need to write fr<rr
    {
        cout << "\nUnderflow";
        return;
    }
    NODE *a = fr;
    if (fr == rr)
    {
        fr = rr = NULL; // single node
    }
    else
    {
        // delete from front end
        fr = a->getNext();
    }
    delete a;
}
void Queue::display()
{
    if (fr == NULL)
    {
        cout << "\nEmpty queue";
        return;
    }
    NODE *a = fr;
    cout << "\nData:\n";
    while (a != NULL)
    {
        cout << " " << a->getData();
        a = a->getNext();
    }
}
Queue::~Queue()
{
    // delete first node
    NODE *a = fr;
    while (fr != NULL)
    {
        fr = a->getNext();
        delete a;
        a = fr;
    }
    rr = NULL;
}
void Queue::menu()
{
    int opt, d;
    while (1)
    {
        cout << "\nMenu\n1.Insert\n2.Remove\n3.Display\n4.Exit\n5.Option";
        cin >> opt;
        if (opt > 3)
            break;
        switch (opt)
        {
        case 1:
            cout << "\nData";
            cin >> d;
            insert(d);
            break;
        case 2:
            remque();
            break;
        case 3:
            display();
            break;
        }
    }
}
int main()
{
    Queue q;
    q.menu();
    return 0;
}