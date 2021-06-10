#include <iostream>
#include <climits>
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

struct Info{
    int size;
    int min;
    int max;
    int ans;
    bool isBst;
};

Info largestBst(Node* root){
    if(root == NULL){
        return {0,INT_MAX, INT_MIN, 0, true};
    }
    if(root->left == NULL && root->right == NULL){
        return {1,root->data, root->data, 1, true};
    }
    Info leftInfo = largestBst(root->left);
    Info rightInfo = largestBst(root->right);

    Info curr;
    curr.size = 1 + leftInfo.size + rightInfo.size;

    if(leftInfo.isBst && rightInfo.isBst && leftInfo.max < root->data && rightInfo.min > root->data){
        curr.min = min(min(leftInfo.min,rightInfo.min), root->data);
        curr.max = max(max(leftInfo.max, rightInfo.max), root->data);
        curr.ans = curr.size;
        curr.isBst = true;
        return curr;
    }
    curr.min = min(min(leftInfo.min,rightInfo.min), root->data);
    curr.max = max(max(leftInfo.max, rightInfo.max), root->data);
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBst = false;
    return curr;
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(3);
    root->right = new Node(5);
    root->right->right = new Node(2);

    Info info = largestBst(root);

    if(info.isBst){
        cout << "Is BsT";
    }
    else{
        cout << "Not BST";
    }

    return 0;
}
