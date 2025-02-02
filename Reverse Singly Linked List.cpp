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
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insert_at_tail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = tail->next;
}
void reverse_linked_list(Node* &head, Node* temp){
    // Base case: if we're at the last node, make it the new head.
    if(temp->next == NULL){
        head = temp;
        return;
    }
    // Correctly advance using temp->next.
    reverse_linked_list(head, temp->next);
    temp->next->next = temp;
    temp->next = NULL;
}

int main(int argc, char const *argv[])
{
     Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->next = tail;

    insert_at_tail(head,tail,202);
    insert_at_tail(head,tail,404);
    insert_at_tail(head,tail,500);
    printLinkedList(head);

    reverse_linked_list(head,head);
    cout << endl;
    printLinkedList(head);
    return 0;
}
