#include <iostream>
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
void print_Linked_List(Node* &head){
   Node* temp;
    temp  = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void Sort_Linked_List(Node* &head){
    for (Node* i = head; i->next!=NULL; i = i->next)
    {
        for (Node* j = i->next; j!=NULL; j=j->next)
        {
            if(i->data > j->data) swap(i->data, j->data);
        }
        
    }
}
int main(int argc, char const *argv[])
{
    Node* head = NULL;
    Node* tail = NULL;

    int data;
    while(1){
        cin >> data;
        if(data == -1){
            break;
        }
        insert_at_tail(head, tail, data);
    }
    Sort_Linked_List(head);
    print_Linked_List(head);

    return 0;
}
