#include <iostream>

using namespace std;

//Reversing a String Program
// void reverse(string s){
//     if(s.length()==0) return;

//     reverse(s.substr(1));
//     cout << s[0];
    
// }

// int main(){

//     reverse("binod");
//     return 0;
// }

//Replacing pi with 3.14 in a String

// 

//Tower of Hanoi

// void TowerofHanoi(int n, char src, char dest, char helper){

//     if(n==0) return;

//     TowerofHanoi(n-1,src,helper,dest);
//     cout << "Move from " << src << " to " <<dest << endl;
//     TowerofHanoi(n-1,helper,dest,src);

// }

// int main(){

//     TowerofHanoi(4,'A','C','B');

//     return 0;
// }

//Removing Duplicates in a String

// void RemoveDup(string s){
//     if(s.length()==0) return;

//     if(s[0] == s[1]){
//         RemoveDup(s.substr(1));
        
//     }
//     else {
//         cout << s[0];
//         RemoveDup(s.substr(1));
//     }
// }

// int main(){

//     RemoveDup("aaaaaabbbbbbbdeeaecchh");

//     return 0;
// }

//Move all X to end of the String

// void moveXtoEnd(string s){

//     if(s.length() == 0) return;

//     if(s[0] == 'x'){
//         moveXtoEnd(s.substr(1));
//         cout << "x";
//     }

//     else{
//         cout << s[0];
//         moveXtoEnd(s.substr(1));
//     }
    

// }

// int main(){

//     string str;
//     cin >> str;

//     moveXtoEnd(str);

//     return 0;
// }

// void subseq(string s, string ans){
//     if(s.length()==0){
//         cout << ans << endl;
//         return;
//     }
//     char ch = s[0];
//     string rem = s.substr(1);
//     subseq(rem , ans);
//     subseq(rem , ans + ch);
// }

// int main(){

//     subseq("ABCD", "");
//     return 0;
// }

string keypadArr[]={"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void possWords(string s, string ans){
    if(s.length()==0){
        cout << ans << endl;
        return;
    }
    char ch=s[0];
    string str=keypadArr[ch-'0'];

    for(int i=0; i<str.length(); i++){
        possWords(s.substr(1),ans+str[i]);
    }

}
int main(){
    string in;
    cin >> in;
    possWords(in,"");
    return 0;

    
    
}