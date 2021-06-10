#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertBst(Node* root , int val){
    if(root == NULL){
        return new Node(val);
    }
    if(root->data>val){
        root->left = insertBst(root->left, val);
    }
    else{
        root->right = insertBst(root->right, val);
    }

    return root;
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data<<" ";
    inOrder(root->right);
}

Node* search(Node* root, int val){
    if(root == NULL){
        return NULL;
    }
    if(root->data == val){
        return root;
    }
    if(root->data > val){
        return search(root->left,val);
    }
    
        return search(root->right, val);
    
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data <<" ";
    preOrder(root->left);
    preOrder(root->right);
}

Node* preOrderSucc(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node* curr = root;
    while(curr->left!=NULL){
         curr = curr->left;
    }
    return curr;
}

Node* deleteBST(Node* root, int val){
    if(root->data > val){
        root->left = deleteBST(root->left, val);
    }
    else if(root->data < val){
        root->right = deleteBST(root->right,val);
    }
    else if(root->data == val){
        if(root->left == NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->right == NULL){
            Node* temp = root;
            delete root;
            return root->left;
        }
        else if(root->right != NULL){
            Node* temp = preOrderSucc(root->right);
            root->data = temp->data;
            root->right = deleteBST(root->right,temp->data);
        }
    }
    return root;
}

Node* constructBst(int preOrder[], int* preOrderIdx, int key, int min, int max, int n){
    if(*preOrderIdx >= n){
        return NULL;
    }

    Node* root = NULL;
    if(key > min && key < max){
        root = new Node(key);
        (*preOrderIdx)++;
        if(*preOrderIdx<n){
            root->left = constructBst(preOrder, preOrderIdx, preOrder[*preOrderIdx], min, key, n);
        }
        if(*preOrderIdx < n){
            root->right = constructBst(preOrder, preOrderIdx , preOrder[*preOrderIdx], key , max , n);
        }
    }
    return root;
}

bool isBst(Node* root, Node* min = NULL, Node* max = NULL){
    if(root == NULL){
        return true;

    }
    if(min!= NULL && root->data < min->data){
        return false;
    }
    if(max!= NULL && root->data > max->data){
        return false;
    }
    bool leftValid = isBst(root->left, min , root);
    bool rightValid = isBst(root->right, root, max);

    return leftValid and rightValid;
}

void zigzagTraversal(Node* root){
    if(root == NULL){
        return;
    }

    stack<Node*> currStk;
    stack<Node*> nextLevel;
    bool leftToRight = false;
    currStk.push(root);

    while(!currStk.empty()){
        Node* node = currStk.top();
        currStk.pop();
        if(node){
            cout << node->data <<" ";
            if(leftToRight){
                if(node->left){
                nextLevel.push(node->left);
                }
                if(node->right){
                    nextLevel.push(node->right);
                }

            }
            else{
                if(node->right){
                    nextLevel.push(node->right);
                }
                if(node->left){
                nextLevel.push(node->left);
                }
            }
        }
        if(currStk.empty()){
            swap(currStk, nextLevel);
            leftToRight = !leftToRight;
        }
    }
}

bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    else if(root1 == NULL || root2 == NULL){
        return false;
    }
    else{
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left,root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);
        return (cond1 and cond2 and cond3);
    }
    return false;

}

int main(){
    Node* root = NULL;

    root = insertBst(root,4);
    insertBst(root,2);
    insertBst(root,7);
    insertBst(root,3);
    insertBst(root,6);
    insertBst(root,8);

    inOrder(root);
    cout << endl;
    Node* root2 = new Node(5);
    // deleteBST(root,4);
    // inOrder(root);
    if(isIdentical(root,root2)){
        cout << "Identical";
    }
    else{
        cout <<" not identical";
    }
    // int preOrderArr[] = {10 , 2, 1 , 13, 11};
    // int idx = 0;
    // int n = 5;

    // Node* root = constructBst(preOrderArr, &idx, preOrderArr[0], INT_MIN, INT_MAX, n);
    // preOrder(root);

    // root->right->right = new Node(14);
    // cout << endl;

    // preOrder(root);

    // if(isBst(root,NULL, NULL)){
    //     cout << "\nValid BST";
    // }else{
    //     cout <<"\nInvalid BST";
    // }

    return 0;
}