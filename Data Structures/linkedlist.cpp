#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node* getNewNode(int data){
    Node* node = new Node;
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Insert at the begin
void insert(Node* root,int data){
    if (root->next==NULL)
    {
        cout << "New Linked List created with data :" << data<<"\n";
        Node *newNode = getNewNode(data);
        root->next = newNode;
        newNode->prev = root;
        return;
    }
    insert(root->next, data);
}

// void remove(Node* root,int data){
//     if(root->next == NULL)
// }

void printList(Node* root){
    if(root->next==NULL){
        return ;
    }
    cout << root->next->data<<"->";
    printList(root->next);
}

int main(int argc, char const *argv[])
{
    // cout << sizeof(int) << '\n';
    Node *list = new Node;
    // cout<< list<< "\n";
    insert(list,5);
    insert(list, 6);
    insert(list, 7);
    cout << "\n";
    printList(list);
    cout <<"\t"<<"List Printed"<< "\n";

    cout << "\n";
    return 0;
}
