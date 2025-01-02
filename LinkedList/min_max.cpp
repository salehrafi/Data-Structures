#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Node2
{
public:
    int data2;
    Node2 *next;
    Node2(int data2)
    {
        this->data2 = data2;
        this->next = NULL;
    }
};

void insert_node_at_tail(Node *&head, Node* &tail, int data, int cnt)
{
    Node* newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = tail->next;
}
void insert_node_at_tail2(Node2 *&head, Node2 *&tail, int data)
{
    Node2 *newNode = new Node2(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = tail->next;
}
void compare_node(Node *head, Node2 *head2, int cnt)
{
    Node *temp = head;
    Node2 *tmp = head2;
    bool ok = true;
    while (temp != NULL && tmp != NULL)
    {
        if (temp->data != tmp->data2)
        {
            ok = false;
            break;
        }
        temp = temp->next;
        tmp = tmp->next;
    }
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
}

void Min_Max(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *temp = head;
    int min = head->data;
    int max = head->data;

    while (temp != NULL)
    {
        if (temp->data < min)
        {
            min = temp->data;
        }
        if (temp->data > max)
        {
            max = temp->data;
        }
        temp = temp->next;
    }

    cout << max - min << endl;
}
void khoj_the_search(Node* head, int val){
    Node* temp = head;
    int cnt = 0;
    
    while (temp != NULL) {
        if (temp->data == val) {
            cout << cnt << "\n";
            return;
        }
        temp = temp->next;
        cnt++;
    }
    
    cout << "-1\n";
}
void print_LL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void sort_List(Node *head)
{
    for (Node *i = head; i->next != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
                swap(i->data, j->data);
        }
    }
}
Node* deleteDupli(Node* head) {
    Node* temp = head; 

    while (temp != NULL) {
        Node* s_temp = temp; 

        while (s_temp->next != NULL) {
            
            if (s_temp->next->data == temp->data) {
                Node* dupli = s_temp->next;  
                s_temp->next = s_temp->next->next;  

                delete dupli;
            } else {
                s_temp = s_temp->next;
            }
        }
        temp = temp->next;
    }
    return head;
}

int main(int argc, char const *argv[])
{
    int n,cnt=0;
        Node* head = NULL;
        Node* tail = NULL;
        int data;
        while (1)
        {
            cin >> data;
            if (data == -1)
            {
                break;
            }
            insert_node_at_tail(head, tail, data,cnt++);
        }
       
    deleteDupli(head);
    print_LL(head);
    // sort_List(head);
    return 0;
}
