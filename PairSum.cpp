#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];

    }
    int s;
    cin>> s;
    int low=0;
    int high=n-1;

    while(low<high){
        if(arr[low]+arr[high]==s){
            cout << "TRUE" << " " <<low+1<<" " <<high+1;
            return 1;
        }
        else if(arr[low]+arr[high]<s){
            low++;
         }
        else{
            high--;
        }
    }

    cout << "FALSE";
    return 0;


}