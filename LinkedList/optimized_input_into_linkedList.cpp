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

int main(int argc, char const *argv[])
{
    Node* head = NULL;
    Node* tail = NULL;

    int data;
    while (true)
    {
        cin >> data;
        if(data == -1){
            break;
        }
        insert_at_tail(head,tail,data);
    }
    printLinkedList(head);
    return 0;
}
