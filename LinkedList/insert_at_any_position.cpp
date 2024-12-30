#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    Node(int data){
        this->data=data;
        this->next = NULL;
    }
};

void printLinkedList(Node* head){
    Node* temp;
    temp  = head;
    while(temp!=NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void insert_at_any_position(Node* &head, int pos, int data){
    Node* newNode = new Node(data);
    Node* temp;
    temp = head;
    for (int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    
}

int main(int argc, char const *argv[])
{
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);

    head->next = a;
    a->next = b;

    insert_at_any_position(head,2,202);
    insert_at_any_position(head,3,404);
    insert_at_any_position(head,4,500);
    printLinkedList(head);

    return 0;
}
