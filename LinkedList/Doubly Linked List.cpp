#include<iostream>
using namespace std;

class Node{
    public:
        Node* prev;
        int data;
        Node* next;

    Node(int data){
        this->prev = nullptr;
        this->data = data;
        this->next = nullptr;
    }
};

void forword_print_LL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data<< " ";
        temp = temp->next;
    }
    cout << endl;
}
void reverse_print_LL(Node* tail){
    Node* temp = tail;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->prev;
    } cout << endl;
}
void insert_at_head(Node* &head,Node* &tail, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    head->prev = newNode;
    head = newNode;
}
void insert_at_tail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
void insert_at_any_position(Node* &head, int data, int pos){
    Node* newNode = new Node(data);
    Node* temp = head;
    for(int i=0;i<pos-1;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;

}
void delete_from_head(Node* &head, Node* &tail){
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;

    if(head==NULL){
        tail = NULL;
        return;
    }
    head->prev = NULL;
}
void delete_from_tail(Node* &head, Node* &tail){

    Node* deleteNode = tail;
    tail = tail->prev;
    delete deleteNode;
    
    if(tail == NULL){
        head = NULL;
        return;
    }
    tail->next = NULL;
}
void delete_Node_at_any_position(Node* &head, int pos){
    
    if(head == NULL){
        return;
    }
    Node* temp = head;
    Node* deleteNode = NULL;

    for (int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }
    deleteNode = temp->next;
    temp->next = deleteNode->next;
    temp->next->prev = temp;
    delete deleteNode;
}
int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->prev = head;
    a->next = tail;
    tail->prev = a;

    insert_at_head(head,tail,0);
    insert_at_tail(head,tail,40);

    insert_at_any_position(head,5,1);
    insert_at_any_position(head,6,2);

    delete_from_head(head,tail);
    delete_from_head(head,tail);

    delete_from_tail(head,tail);
    delete_from_tail(head,tail);

    delete_Node_at_any_position(head,0);
    // delete_Node_at_any_position(head,1); 
    /* segmentation fault will shown for this line beacause we want to accessing the head and tail node which are the last node*/

    forword_print_LL(head);
    reverse_print_LL(tail);

    return 0;
}