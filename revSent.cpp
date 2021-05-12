#include <iostream>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

void reverseString(string  s){
    stack<string> st;

    for(int i=0; i<s.length(); i++){
        string word = "";
        while(s[i] != ' ' && i<s.length()){
            word +=s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
        cout << st.top() <<" ";
        st.pop();
    }
}

void insertAtBottom(stack<int> &stk, int ele){
    if(stk.empty()){
        stk.push(ele);
        return;
    }
    int topEle = stk.top();
    stk.pop();
    insertAtBottom(stk,ele);
    stk.push(topEle);
}

void reverseStack(stack<int> &stk){
    if(stk.empty()){
        return;
    }

    int topEle = stk.top();
    stk.pop();
    reverseStack(stk);
    insertAtBottom(stk,topEle);
}

int prefixEvaluation(string s){
    stack<int> stk;

    for(int i = s.length()-1; i>=0; i--){
        if(s[i] >='0' && s[i] <='9'){
            stk.push(s[i]-'0');
        }
        else{
            int op1 = stk.top();
            stk.pop();
            int op2 = stk.top();
            stk.pop();
            switch(s[i]){
                case '+':
                        stk.push(op1+op2);
                        break;
                case '-':
                stk.push(op1 - op2);
                break;
                case '*':
                stk.push(op1 * op2);
                break;
                case '/':
                stk.push(op1 / op2);
                break;
                case '^':
                stk.push(pow(op1,op2));
                break;
            }
        }
    }
    return stk.top();
}

int prec(char ch){
    if(ch == '^'){
        return 3;
    }
    if(ch == '*' || ch == '/'){
        return 2;
    }
    if(ch == '+' || ch == '-'){
        return 1;
    }
    return -1;
}

string infixToPostfix(string s){
    stack<char> stk;
    string res = "";
    for(int i =0; i<s.length(); i++){
        if(s[i]>='0' && s[i]<='9'){
            res += s[i];

        }
        else if(s[i] == '('){
            stk.push('(');
        }
        else if(s[i] == ')'){
            while(!stk.empty() && (stk.top() != '(')){
                res+=stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else{
            while(!stk.empty() && (prec(stk.top())>prec(s[i]))){
                res += stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        }
    }
    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }
    return res;
}

string infixToPrefix(string s){
    reverse(s.begin(),s.end());
    for(int i=0; i<s.length();i++){
        if(s[i]=='(') {s[i] =')';}
        else if(s[i]==')') {s[i] ='(';}
    }
    s = infixToPostfix(s);
    reverse(s.begin(),s.end());
    return s;

}

bool isValid(string s){
    stack<char> stk;
    for(int i =0; i<s.length(); i++){
        if((s[i] == '(') || (s[i] == '{') || (s[i] == '[')){
            stk.push(s[i]);
        }
        else if(s[i] == ')'){
            if(stk.top()=='('){
                stk.pop();
            }
        }
        else if(s[i] == ']'){
            if(stk.top() == '['){
                stk.pop();
            }
        }
        else if(s[i] == '}'){
            if(stk.top() == '{'){
                stk.pop();
            }
        }
    }
    if(stk.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
//  string s = "Hey, How are you doing?";
//  reverseString(s);

// stack<int> stk;
// stk.push(3);
// stk.push(5);
// stk.push(2);
// stk.push(1);
// while(!stk.empty()){
//     cout << stk.top() << " ";
//     stk.pop();
// }
// cout << endl;

// reverseStack(stk);

// while(!stk.empty()){
//     cout << stk.top() << " ";
//     stk.pop();
// }
// cout << endl;
if(isValid("[{()]}")){
    cout << "true";
}
else{
    cout << "false";
}


 return 0;
}