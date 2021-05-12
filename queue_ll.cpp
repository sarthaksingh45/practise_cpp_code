#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{

    Node* front;
    Node* back;
    public:

    Queue(){
        front = NULL;
        back = NULL;
    }

    void push(int val){
        Node* n = new Node(val);
        if(front == NULL){
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = back->next;

    }

    void pop(){
        if(front == NULL){
            cout << "No Elements to POP" << endl;
            return ;
        }
        Node* toDelete = front;
        front = front->next;
        delete toDelete;
    }

    int peek(){
        if(front == NULL){
            cout << "No elements" << endl;
            return -1;
        }
        return front->data;
    }
    
    bool empty(){
        if(front == NULL){
            return true;
        }
        return false;
    }
};

int main(){
    Queue que;
    que.push(4);
    que.push(5);
    que.push(6);
    cout << que.peek() << " ";
    que.pop();
    cout << que.peek() << " ";
    que.pop();

cout << que.peek() << " ";
    que.pop();


cout << que.peek() << " ";
    que.pop();
cout << que.empty();
return 0;

}