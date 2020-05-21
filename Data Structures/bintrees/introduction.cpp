#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

template <typename T>
struct node{
    T data;
    node* left;
    node *right;
};

template <typename T>
struct node* newNode(T data){
    struct node *n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
template <typename T>
void insert(node* root, T data){
    
}


int main(int argc, char const *argv[])
{
    struct node* binaryTree;

    return 0;
}
