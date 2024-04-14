#include<bits/stdc++.h>
/* Sakshi */
using namespace std;

class Node {
public:
	int data;
	Node (){};
	Node* next;
	Node* prev;
    void push(Node** head_ref, int new_data);
    void deleteNode(Node** head_ref, Node* del);
};
void Node :: push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	(*head_ref) = new_node;
}

void Node :: deleteNode(Node** head_ref, Node* del)
{
	if (*head_ref == NULL || del == NULL)
		return;
	if (*head_ref == del)
		*head_ref = del->next; 
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del);
	return;
}

void printList(Node* node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}
int main()
{
	// use memory selector here
	Node x;
	Node* head = NULL;
	x.push(&head, 2);
	x.push(&head, 4);
	x.push(&head, 8);
	x.push(&head, 10);
	cout << "Original Linked list ";
	printList(head);
	x.deleteNode(&head, head); 
	x.deleteNode(&head, head->next); 
	x.deleteNode(&head, head->next);
	cout << "\nModified Linked list ";
	printList(head);
	return 0;
}