#include<bits/stdc++.h>
// https://www.codingninjas.com/studio/problems/replace-the-linked-list-with-the-sum-of-nodes-between-0_1380873?count=25&page=1&search=&sort_entity=order&sort_order=ASC&attempt_status=NOT_ATTEMPTED&leftPanelTab=0
using namespace std;

class Node
{
	public:
	int data;
    Node * next;
	Node(int x)
	{
		data=x;
		next=NULL;
	}
};

Node *replaceWithSum(Node *head)
{
    bool flg = 0,check = 0;
    if(head->data == 0)
        check = 1;
    Node* fast = head->next,*slow = head;
    int sum = head->data;//intially to val of head
    while (fast != NULL)
    {   
        sum = sum + (fast->data);
        if(fast->data == 0){
            flg = 1;
            slow->data = sum;
            sum = 0;
            slow->next = fast->next;
            if(fast->next != NULL)
                slow = fast->next;
        }
        fast = fast->next;
    }
    if(!flg && check)
        head = head->next;
    return head;
}
