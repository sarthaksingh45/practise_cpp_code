#include <iostream>
#include <vector>
using namespace std;

void maxSubstr(string s){
    int maxLen =0;
    vector<int> arr(256,-1);
    int start =-1;
    for(int i=0; i<s.size(); i++){
        if(arr[s[i]]>start){
            start = arr[s[i]];
        }
        arr[s[i]] = i;
        maxLen = max(maxLen, i-start);
    }
    cout << maxLen;
}

int main(){
    string str ="kuch bhi";
    maxSubstr(str);
    return 0;
}