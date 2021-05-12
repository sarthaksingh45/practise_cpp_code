#include <iostream>
using namespace std;

// #define n 100

class Stack{
    int* arr;
    int top;
    int n=100;

    public:
    Stack(){
        arr = new int[n];
        top = -1;
    }
    Stack(int x){
        n=x;
        arr = new int[n];
        top = -1;
    }
    
    void push(int x){
        if(top==n-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top] =x;
    }

    void pop(){
        if(top == -1){
            cout << "Nothing to pop" << endl;
            return ;

        }
        top--;

    }
    int topElement(){
        if(top==-1){
            cout << "Nothing in Stack"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top==-1;
    }
};

int main(){
    Stack st =Stack();
    st.push(3);
    st.push(2);
    st.push(40);
    st.push(4);
    st.push(5);
    // st.pop();
    cout << st.topElement()<<endl;
    st.pop();
    st.pop();
    cout << st.topElement() <<endl;
    cout << st.isEmpty();

    return 0;

}