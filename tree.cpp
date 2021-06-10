#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preOrderTraversal(Node* root){
    if(root==NULL) return;
    cout << root->data;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    if(root==NULL) return;
    inOrderTraversal(root->left);
    cout << root->data <<" ";
    inOrderTraversal(root->right);
}

int search(int inOrder[], int start, int end, int curr){
    for(int i= start; i<=end; i++){
        if(inOrder[i]==curr){
            cout << i <<endl;
            return i;
        }
    }
    return -1;
}

Node* buildTree(int preOrder[], int inOrder[], int start, int end){
    if(start>end){
        return NULL;
    }
    static int idx = 0;
    int curr = preOrder[idx];
    Node* node = new Node(curr);
    idx++;
    if(start == end){
        return node;
    }
    int pos = search(inOrder,start,end,curr);
    node->left = buildTree(preOrder, inOrder, start ,pos-1);
    node->right = buildTree(preOrder,inOrder, pos+1, end);
    return node;
}

Node* buildTreePost(int postOrder[], int inOrder[], int start, int end){
    if(start>end){
        return NULL;
    }
    static int idx = 4;
    int curr = postOrder[idx];
    Node* node = new Node(curr);
    idx--;
    if(start == end){
        return node;
    }
    int pos = search(inOrder,start,end,curr);
    node->right = buildTreePost(postOrder,inOrder, pos+1, end);
    node->left = buildTreePost(postOrder, inOrder, start ,pos-1);
    return node;
}

int sumAtKLevel(Node* root, int k){
    if(root == NULL){
        return -1;
    }
    queue<Node*> que;
    que.push(root);
    que.push(NULL);

    int sum =0;
    int level=0;

    while(!que.empty()){
        Node* top = que.front();
        que.pop();
        if(top!=NULL){
            if(level==k){
                sum += top->data;
            }
            if(top->left) que.push(top->left);
            if(top->right) que.push(top->right);
        }
        else if(!que.empty()){
            que.push(NULL);
            level++;
        }
    }
    return sum;
}

void levelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> que;
    que.push(root);
    que.push(NULL);

   
    
    while(!que.empty()){
        Node* node = que.front();
     
        que.pop();
        if(node!=NULL){
            cout << node->data <<" ";
            if(node->left!=NULL) {
             que.push(node->left);}
                
            if(node->right!=NULL){
             que.push(node->right);}
               
        }
        else if(!que.empty()){
            que.push(NULL);
        }
    }

}

int nodeCount(Node* root){
    if(root == NULL){
        return 0;
    }
    return nodeCount(root->left)+nodeCount(root->right)+1;
}

int sumNode(Node* root){
    if(root == NULL){
        return 0;
    }
    return sumNode(root->left)+sumNode(root->right)+root->data;
}

int calcHeight(Node* root){
    if(root==NULL){
        return 0;
    }

    return max(calcHeight(root->left),calcHeight(root->right)) + 1;
}

int calcDiameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftHeight = calcHeight(root->left);
    int rightHeight = calcHeight(root->right);

    return max(leftHeight+rightHeight+1, max(calcDiameter(root->left),calcDiameter(root->right)));
}

int calcDiameterTwo(Node* root, int* height){
    if(root==NULL){
        *height = 0;
        return 0;
    }
    int lh =0, rh=0;
    int leftDia = calcDiameterTwo(root->left,&lh);
    int rightDia = calcDiameterTwo(root->right,&rh);
    *height = max(lh,rh) +1;
    return max(lh+rh+1,max(leftDia,rightDia));


}

bool balancedTree(Node* root,int* height){
    if(root == NULL){
        return true;

    }
    int lh =0, rh =0;
    if(balancedTree(root->left,&lh)==false){
        return false;
    }
    if(balancedTree(root->right,&rh)==false){
        return false;
    }
    *height = max(lh, rh ) + 1;
    if(abs(lh-rh)<=1){
        return true;
    }
    else return false;
}

void sumReplace(Node* root){
    if(root == NULL){
        return;
    }
    sumReplace(root->left);
    sumReplace(root->right);
    if(root->left) root->data += root->left->data;
    if(root->right) root->data += root->right->data;
    return;
}

void rightView(Node* root){
    if(root == NULL){
        return ;
    }
    queue<Node*> que;
    que.push(root);
    while(!que.empty()){
        int n = que.size();
        for(int i=0; i<n; i++){
            Node* curr = que.front();
            que.pop();
            if(i==n-1){
                cout << curr->data <<" ";
            }
            if(curr->left != NULL){
                que.push(curr->left);
            }
            if(curr->right != NULL){
                que.push(curr->right);
            }

        }
    }
}

Node* LCS(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;

    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* left = LCS(root->left,n1,n2);
    Node* right = LCS(root->right,n1,n2);
    if(left!=NULL && right!=NULL){
        return root;
    }
    if(left == NULL && right == NULL){
        return NULL;
    }
    if(left!= NULL){
        return LCS(left,n1,n2);
    }
    return LCS(right,n1,n2);
}

int findDist(Node* root, int n, int dist){
    if(root == NULL){
        return -1;
    }
    if(root->data == n){
        return dist;
    }
    int leftDis = findDist(root->left, n, dist+1);
    int rightDis = findDist(root->right, n, dist +1);
    if(leftDis>-1){
        return leftDis;
    }
    return rightDis;
}

int distBtwNodes(Node* root , int n1, int n2){
    Node* lcs = LCS(root,n1,n2);
    int d1 = findDist(lcs,n1,0);
    int d2 = findDist(lcs, n2,0);
    return d1+d2;
}

void flattenTree(Node* root){
    if(root==NULL || (root->left==NULL && root->right== NULL)){
        return;
    }
    if(root->left!=NULL){
        flattenTree(root->left);
        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        Node* t=root->right;
        while(t->right!=NULL){
            t=t->right;
        }
        t->right = temp;
    }
    flattenTree(root->right);
}

void printSubTree(Node* root, int k){
    if(root == NULL){
        return;
    }
    if(k==0){
        cout <<root->data <<" ";
        return;
    }
    printSubTree(root->left, k-1);
    printSubTree(root->right,k-1);
    
}

int printNodesAtK(Node* root, Node* target, int k){
    if(root == NULL){
        return -1;
    }
    if(root == target){
        printSubTree(root,k);
        return 0;
    }

    int dl = printNodesAtK(root->left, target, k);
    if(dl!=-1){
        if(dl+1==k){
            cout << root->data <<" ";
        }
        else{
            printSubTree(root->right,k-2-dl);
        }
        return dl+1;
    }

    int dr = printNodesAtK(root->right, target, k);
    if(dr!=-1){
        if(dr+1==k){
            cout << root->data <<" ";
        }
        else{
            printSubTree(root->left,k-dr-2);
        }
        return dr+1;
    }
    return -1;
}

int maxSumPathUtil(Node* root, int* ans){
    if(root == NULL){
        return -1;
    }
    int leftSum = maxSumPathUtil(root->left,ans);
    int rightSum = maxSumPathUtil(root->right,ans);
    int nodeMaxx = max(max(root->data,root->data+leftSum), max(root->data+rightSum,root->data+leftSum+rightSum));
    *ans = max(*ans,nodeMaxx);
    return max(max(root->data, root->data+leftSum),root->data+rightSum);
}

int maxSumPath(Node* root){
    int ans=0;
    maxSumPathUtil(root,&ans);
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);

    // int preOrderArr[] = {1,2,4,3,5};
    // int inOrderArr[] = {4,2,1,5,3};
    // int postOrderArr[] = {4,2,5,3,1};
    // Node* newRoot = buildTreePost(postOrderArr,inOrderArr,0,4);

    // inOrderTraversal(newRoot);
    // int height =100;
    // cout << calcDiameterTwo(root,&height);

    // inOrderTraversal(root);
    // sumReplace(root);
    // cout << endl;
    // inOrderTraversal(root);

    // int height =0;
    // if(balancedTree(root,&height)) cout << " True" ;
    // else cout << "False";
    // rightView(root);
    // inOrderTraversal(root);
    // cout << endl;
    // flattenTree(root);
    // inOrderTraversal(root);

    cout << maxSumPath(root);


    return 0;

}