#include <iostream>
using namespace std;

#define n 20

class Queue{
    int* arr;
    int front;
    int back;

    public:
    Queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x){
        if(back == n-1){
            cout << "Queue OverFlow" <<endl;
        }
        back++;
        arr[back]=x;
        if(front == -1){
            front++;
        }
    }

    void pop(){
        if(front == -1 || front>back){
            cout<<"Nothing to Pop";
            return;
        }
        front++;
    }

    int peek(){
        if(front == -1 || front>back){
            cout << "No elements";
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        if(front == -1 || front> back){
            return true;
        }
        return false;
    }
};

int main(){
    Queue que;
    que.push(3);
    que.push(5);
    que.push(6);
    cout << que.peek() <<" ";
    que.pop();
    cout << que.peek() << " ";
    que.pop();
    que.pop();
    cout << que.empty() <<endl;
    return 0;
}