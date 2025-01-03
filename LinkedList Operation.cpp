#include<iostream>
using namespace std;
int pos = 0;

class Node{
    public:
        int data;
        Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print_LL(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

void insert_at_head(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    pos++;
    print_LL(head);
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
    pos++;
    print_LL(head);
}
void delete_at_head(Node* &head){
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
    pos--;
}
void delete_at_any_position(Node* &head, int pos){
    Node* deleteNode = NULL;
    Node* temp = head;
    for (int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }
    deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
    pos--;
    print_LL(head);
}

void delete_at_tail(Node* &head, Node* &tail) {
    if (head == NULL) return;
    Node* temp = head;

    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }
    tail = temp;
    delete temp->next;
    pos--;
    temp->next = NULL;
    print_LL(head);
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int x,v;

    int n;
    cin >> n;
    while(n--){
    cin >> x >> v;
    if(x==0){
        insert_at_head(head,v);
    }else if(x==1){
        insert_at_tail(head,tail,v);
    }else{
        if(v==0){
            delete_at_head(head);
        }else if (v==1)
        {
            delete_at_tail(head, tail);
        }else{
            delete_at_any_position(head,v);
        }
    }
    }
    // print_LL(head);
    return 0;
}
