#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();

    char arr[n+1];
    cin.getline(arr, n);
    cin.ignore();

    int i=0;
    int st=0,et=0;
    int maxLen=0, currLen=0;

    while(i<n){
        if(arr[i] == ' ' || arr[i] == '\0'){
            if(currLen > maxLen){
                maxLen = currLen;
                et=i;
            }
            currLen=0;
            
        }
        else
            currLen++;
        i++;
    }

    cout << maxLen << endl;
    for(int i=0; i<maxLen; i++){
        cout << arr[et-maxLen+i];
    }
    return 0;


}