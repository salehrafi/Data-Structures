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

void insert_node_at_tail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = tail->next;
}
void Insert_node_at_font(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
void Print_Linked_list(Node *head)
{
    Node *temp = head;
    int data, cnt = -1;
    cin >> data;
    while (temp != NULL)
    {
        if (data == temp->data)
        {
            cnt++;
        }
        // cout << temp->data << " ";
        temp = temp->next;
    }
    cout << cnt << endl;
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
    int n;
    cin >> n;
    while (n--)
    {

        Node *head = NULL;
        Node *tail = NULL;
        int pos,data;
        cin >> pos >>data;
        if(pos == 0){
            Insert_node_at_font(head,data);
        }else if(pos == 1){
            insert_node_at_tail(head,tail,data);
        }else if(pos ==2){
            delete_Node_at_any_position(head,data);
        }
        // while (1)
        // {
        //     cin >> data;
        //     if (data == -1)
        //     {
        //         break;
        //     }
        //     insert_node_at_tail(head, tail, data);
        // }
        // sort_List(head);
        Print_Linked_list(head);
        // cout << tail->data - head->data << endl;
    }
    return 0;
}
