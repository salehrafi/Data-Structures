#include<iostream>
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
void print_linked_list(Node* head){
    Node* temp;
    temp = head;

    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void node_counter(Node* head){
    Node* temp;
    temp = head;
    int counter = 0;
    while(temp!=NULL){
        counter++;
        temp=temp->next;
    }
    cout << "\nNumber of Node is: " << counter << endl;
}
int main(int argc, char const *argv[])
{
    Node* head = NULL;
    Node* tail = NULL;

    int input;
    while(true){
        cin >> input;
        if(input == -1){
            break;
        }
        insert_at_tail(head,tail,input);
    }
    print_linked_list(head);
    node_counter(head);

    return 0;
}
