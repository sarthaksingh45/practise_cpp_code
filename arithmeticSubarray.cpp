#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    int arr[n];
    for( int i=0; i<n; i++){
        cin >> arr[i];
    }

    int pd=arr[1]-arr[0];
    int current=2;
    int ans=2;

    for(int i =1; i<n; i++){
        if(arr[i+1]-arr[i]==pd){
            current++;
            ans= max( ans, current);

        }
        else{
            pd=arr[i+1]-arr[i];
            current=2;
        }
    }

    cout<< ans<<endl;

}