#include <iostream>
#include <queue>
using namespace std;

class Stack{
    int N;
    queue<int> q1;
    queue<int> q2;
    public:

    Stack(){
        N=0;
    }

    void push(int val){
       q1.push(val);
       N++;
    }
    void pop(){
       if(q1.empty()){
           cout << "Stack Empty";
           return;
       }
       while(q1.size()!=1){
           q2.push(q1.front());
           q1.pop();
       }
       N--;
       q1.pop();
       queue<int> temp = q2;
       q2 = q1;
       q1 =temp;

    }

    int top(){
         if(q1.empty()){
           cout << "Stack Empty";
           return -1;
       }
       while(q1.size()!=1){
           q2.push(q1.front());
           q1.pop();
       }
        return q1.front();
       
    }

    bool empty(){
        if(q1.empty()){
            return true;
        }
        return false;
    }


};


int main(){

    Stack stk;
    stk.push(3);
    stk.push(5);
    stk.push(6);
    cout << stk.top() <<" ";
    stk.pop();
    stk.pop();
    cout << stk.top() << " ";
    stk.pop();
    cout << stk.empty() <<endl;
    return 0;
}