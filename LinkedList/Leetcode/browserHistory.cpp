// https://leetcode.com/problems/design-browser-history/description/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
class Node
{
public:
    string data;
    Node *next;
    Node *back;
    Node() : data(0), next(nullptr), back(nullptr) {}
};
class BrowserHistory
{
public:
    Node *currPage;

    BrowserHistory(string homepage)
    {
        currPage = new Node(homepage);
    }

    void visit(string url)
    {
        Node *newNode = new Node(url);
        currPage->next = newNode;
        newNode->back = currPage;
        currPage = newNode;
    }

    string back(int steps)
    {
        while (steps)
        {
            if (currPage->back != nullptr)
                currPage = currPage->back;
            else
                break;
            steps--;
        }
        return currPage->data;
    }

    string forward(int steps)
    {
        while (steps)
        {
            if (currPage->next != nullptr)
                currPage = currPage->next;
            else
                break;
            steps--;
        }
        return currPage->data;
    }
    
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */