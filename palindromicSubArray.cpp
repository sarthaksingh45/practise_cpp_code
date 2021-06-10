#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPalindrome(int n){
    int temp = n, number = 0;
    while(temp > 0){
        number = number*10 + (temp%10);
        temp = temp/10;
    }
    if(number == n){
        return true;
    }
    return false;
}

int palindromeIndex(vector<int> arr, int k){
    int number = 0;
    for(int i = 0; i<k; i++){
        number = number*10 + arr[i];
    }
    if(isPalindrome(number)){
        return 0;
    }
    for(int i=k; i<arr.size(); i++){
        number = (number % (int)pow(10,k-1))*10 + arr[i];
        if(isPalindrome(number)){
            return i-k+1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {2,3,5,1,1,5};
    int result = palindromeIndex(arr,4);
    if(result==-1){
        cout << "No palindrome Exists" << endl;
    }
    else{
        for(int i=result; i<result+4; i++){
            cout << arr[i] <<" ";
        }
    }

    return 0;
}