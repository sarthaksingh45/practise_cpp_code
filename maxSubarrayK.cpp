#include <iostream>
using namespace std;

int maxSubArr(int arr[],int n,int x,int k){
    int sum =0 ;
    int ans;
    for(int i=0; i<k; i++){
        sum += arr[i];
    }
    if(sum < x){
        ans = sum;
    }
    for(int i=k; i<n; i++){
        sum -= arr[i-k];
        sum+= arr[i];
        if(sum < x){
            ans = max(sum,ans);
        }
    }
    return ans;
}

int main(){
    int arr[] = {7,5,4,6,8,9};
    cout << maxSubArr(arr,6,20,3);

    return 0;
}