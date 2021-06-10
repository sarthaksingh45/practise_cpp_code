#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left, *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<Node*> catalan(int start, int end){
    vector<Node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }

    for(int i=start; i<=end; i++){
        vector<Node*> leftsubtrees = catalan(start, i-1);
        vector<Node*> rightsubtrees = catalan(i+1, end);
        for(int j=0; j<leftsubtrees.size(); j++){
            Node* left = leftsubtrees[j];
            for(int k=0; k<rightsubtrees.size(); k++){
                Node* right = rightsubtrees[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data <<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    vector<Node*> trees = catalan(1,3);
    for(int i=0; i<trees.size(); i++){
        cout << (i+1) <<" : ";
        preOrder(trees[i]);
        cout << endl;
    }

    return 0;
}
