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

void print_reverse(Node* &temp){
    // base case
    if(temp == NULL){
        return;
    }
    print_reverse(temp->next); /*
                                    why we write temp->next inside recursion parameter?
                                    because, if we are iterate a array, we should go to next index.
                                    So, Linked list has node, not index so we should write temp->next
                                */
    cout << temp->data << " ";
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
    print_reverse(head);
    return 0;
}
