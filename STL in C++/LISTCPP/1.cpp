// Lists are sequence containers that allow non-conttiguous memory allocation
// As comapared to vectors list has slow traversal
// Normally, when we say a List, we talk about a doubly linked list. For implementing a singly linked list, we use a forward list
#include <bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
void display(list<int> l)
{
    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); ++it)
    {
        cout << " " << *it;
    }
        cout << "\n";
}
int main()
{
    list<int> l1, l2;
    for (int i = 1; i < 10; i++)
    {
        l1.push_back(i * 2);
        l2.push_back(i * 3);
    }
    cout << "\nList1:";
    display(l1);
    cout << "\nList2";
    display(l2);
    cout << "\nList1.front() : " << l1.front();
    cout << "\nList2.front() : " << l2.front();
    cout << "\nList1.back() : " << l1.back();
    cout << "\nList2.back() : " << l2.back();

    cout << "\nlist1.pop_front() : ";
    l1.pop_front();
    display(l1);

    cout << "\nlist2.pop_front() : ";
    l2.pop_front();
    display(l2);

    cout << "\nList1.reverse() : ";
    l1.reverse();
    display(l1);

    cout << "\nList2.reverse() : ";
    l2.reverse();
    display(l2);

    return 0;
}