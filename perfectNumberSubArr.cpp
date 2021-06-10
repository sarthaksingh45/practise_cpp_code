#include <iostream>
#include <cmath>
using namespace std;

bool isPerfect(int n){
    int sum =1;
    for(int i = 2; i<sqrt(n); i++){
        if(n%i == 0){
            if(i == n/i){
                sum += i;
            }
            else{
                sum += i + n/i;
            }
        }
    }
    if(sum == n){
        return true;
    }
    return false;
}

int maxPerfectSubArr(int arr[], int n, int k){
    for(int i=0; i<n; i++){
        if(isPerfect(arr[i])){
            arr[i] = 1;
        }
        else{
            arr[i]= 0;
        }
    }
    int sum = 0, res =0;
    for(int i=0; i<k; i++){
        sum += arr[i];
    }
    res = sum;
    for(int i=k; i<n; i++){
        sum = sum + arr[i] - arr[i-k];
        res = max(sum,res);
    }

    return res;
}

int main(){
    int arr[] = {28,2,3,6,496,99,8128, 24};

    cout << maxPerfectSubArr(arr, 8 ,4);

    return 0;
}