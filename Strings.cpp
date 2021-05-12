#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    // string str;
    // getline(cin, str);
    // cout << str;

    
    // string str1(5, 'n');

    // cout << str1;

    
    // int x = 3;
    // cout << to_string(x)+'3'<< endl;

    // string s1 = "akfdajgkhdnva";
    // for(int i=0; i<s1.length(); i++){
    //     if(s1[i]>='a' && s1[i]<='z'){
    //         s1[i] -= 32;

    //     }
    // }

    // cout << s1 << endl;

    // for(int i=0; i<s1.length(); i++){
    //     if(s1[i]>='A' && s1[i]<='Z')
    //         s1[i] += 32;
    // }

    // transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    // transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    // cout << s1 << endl;

    // string s = "917851905";
    // sort(s.begin(), s.end(), greater<int>());
    // cout << s ;

    string str = "jllllllllllllllaaaaskhfjkgadknv";
    int arraycount[26];
    for(int i=0; i < 26; i++)
        arraycount[i] = 0;
    
    for(int i=0; i<str.length(); i++){
        arraycount[str[i]-'a']++;
    }

    int maxcount=0;
    char ch;
    for(int i=0; i<26; i++){
        if(arraycount[i]>maxcount){
            maxcount = arraycount[i];
            ch='a'+i;
        }
    }
    cout << ch << " "<< maxcount;
    return 0;
}