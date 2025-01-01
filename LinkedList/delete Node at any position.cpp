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
void delete_Node_at_any_position(Node* &head, int pos){
    Node* deleteNode = NULL;
    Node* temp = head;
    for (int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }
    deleteNode = temp->next;
    temp->next = temp->next->next;
    // temp->next = deleteNode->next; //work as same
    delete deleteNode;
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
    delete_Node_at_any_position(head,1);
    cout << endl;
    printLinkedList(head);

    return 0;
}
