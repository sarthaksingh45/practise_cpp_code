#include <iostream>
using namespace std;

void reverse(string s){
    if(s.length()==0){
        cout<<s;
        return;
    }

    char ch = s[0];
    reverse(s.substr(1));
    cout << ch;
}

int main(){
    string s;
    cin >> s;

    int length = s.length();
    if(length%2 == 0){
        reverse(s.substr(0,length/2));
        reverse(s.substr(length/2));

    }
    else{
        reverse(s.substr(0,length/2));
        cout << s[length/2];
        reverse(s.substr((length/2)+1));
    }
    return 0;

}