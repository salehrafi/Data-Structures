#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void Print_Linked_list(Node* head){
    Node* temp;
    temp = head;
    while (temp!=NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void Insert_node_at_font(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
void Insert_node_at_back(Node* head,int data){
    Node* newNode = new Node(data);
    Node* temp;
    temp = head;

    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
int main(){
    Node* head = new Node(10);    
    Node* a = new Node(30);    
    Node* b = new Node(20);
    
    head->next = a;
    a->next = b;

    Insert_node_at_font(head, 5);
    Insert_node_at_back(head,40);
    Insert_node_at_back(head,50);
    Print_Linked_list(head);

    return 0;
}