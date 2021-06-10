#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;

    }
};

void swap(int *a, int* b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void calPointers(Node* root, Node** first, Node** mid, Node** last, Node** prev){
    if(root == NULL){
        return;
    }
    calPointers(root->left, first, mid, last, prev);
    if(*prev && root->data < (*prev)->data){
        if(!*first){
            *first = *prev;
            *mid = root;
        }
        else{
            *last = root;
        }
    }
    *prev = root;
    calPointers(root->right, first, mid, last, prev);
}

void restoreBst(Node* root){
    Node* first, *mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    calPointers(root, &first, &mid, &last, &prev);

    if(first && last){
        swap(&(first->data),&(last->data));
    }
    else{
        swap(&(first->data), &(mid->data));
    }
}

void inOrder(Node* root){
    if(root == NULL){
        return ;
    }

    inOrder(root->left);
    cout << root->data <<" ";
    inOrder(root->right);
}

int main(){

    Node* root = new Node(7);
    root->left = new Node(9);
    root->right = new Node(5);
    root->right->right = new Node(11);
    root->right->left = new Node(8);

    inOrder(root);
    restoreBst(root);
    cout << endl;
    inOrder(root);

    return 0;
}