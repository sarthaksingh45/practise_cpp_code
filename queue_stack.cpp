#include <iostream>
#include <stack>
using namespace std;

// class Queue{
//     stack<int> s1;
//     stack<int> s2;
//     public:
//     void push(int val){
//         s1.push(val);
//     }

//     void pop(){
//         if(s1.empty() && s2.empty()){
//             cout << "Queue is EMpty\n";
//             return;
//         }
//         if(s2.empty()){
//             while(!s1.empty()){
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//         }
//         s2.pop();
//     }
//     int peek(){
//         if(s1.empty() && s2.empty()){
//             cout << "Queue is EMpty\n";
//             return -1;
//         }
//         if(s2.empty()){
//             while(!s1.empty()){
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//         }
//         return s2.top();

//     }

//     bool empty(){
//         if(s1.empty() && s2.empty()){
//             cout << "Queue is EMpty\n";
//             return true;
//         }
//         return false;
//     }
// };

// int main(){
//     Queue que;
//     que.push(3);
//     que.push(4);
//     que.push(5);
//     cout << que.peek() << " ";
//     que.pop();
//      cout << que.peek() << " ";
//     que.pop();
//      cout << que.peek() << " ";
//     que.pop();
//      cout << que.peek() << " ";
//     que.pop();
//     cout << que.empty();

//     return 0;
// }

class Queue{
    stack<int> stk;
    public:
    void push(int val){
        stk.push(val);
    }
    void pop2(){
        if(stk.empty()){
            cout << "Queue is Empty\n";
            return;
        }
        int x = stk.top();
        stk.pop();
        // if(stk.empty()){
        //     return;
        // }
        pop2();
        push(x);
        
    }
    int pop(){
        if(stk.empty()){
            cout <<" Queuwu ";
            return -1;
        }
        int x = stk.top();
        stk.pop();
        if(stk.empty()){
            return x;
        }
        int res = pop();
        push(x);
        return res;
    }
    bool empty(){
        if(stk.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    Queue que;
    que.push(4);
    que.push(7);
    que.push(5);
    que.push(6);
   cout << que.pop() <<" ";
    cout << que.pop() <<" ";
     cout << que.pop() <<" ";
      cout << que.pop() <<" ";
       cout << que.pop() <<" ";

    return 0;
}