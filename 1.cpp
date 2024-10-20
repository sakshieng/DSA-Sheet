#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
    ~Node(){
        int val = this->data;
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << val << endl;
    }
};
void insertAtHead(Node* &head,int data){
    //change in org LL hence take refernce (&)
    Node* tmp = new Node(data);
    tmp->next = head;
    head = tmp;
}
void insertAtTail(Node* &tail,int data){
    Node* tmp = new Node(data);
    tail->next = tmp;
    tail = tmp; 
}
void insertAtPos(Node* tail,Node* &head,int pos,int data){
    Node* tmp = head;
    int cnt = 1;
    //insert at start
    if(pos == 1){
        insertAtHead(head,data);
        return ;
    }
    while (cnt < pos-1)
    {
        tmp = tmp->next;
        cnt++;
    }
    //inserting at last we need to update tail
    if(tmp->next == NULL)
    {
        insertAtTail(tail,data);
        return;
    }
    //tmp is prev node so tyacha next insert cha next honar
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = tmp->next;
    tmp->next = nodeToInsert;
}
void print(Node *&head){
     if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
int main()
{
    Node* node1 = new Node(10);
    Node* head = node1; 
    Node* tail = node1;
    print(head);

    insertAtTail(tail, 12);
    print(head);
    
    insertAtTail(tail, 15);
    print(head);

    insertAtPos(tail,head,4,22);
    print(head);

    cout<<"HEAD " << head->data <<endl;
    cout<<"TAIL " << tail->data << endl;
   return 0;
}