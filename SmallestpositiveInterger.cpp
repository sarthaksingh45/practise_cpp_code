#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n; i++){
        cin >> arr[i];
    }

    const int N=1e5+2;

    bool Idxarr[N];
    for(int i=0;i<N;i++){
        Idxarr[i]=0;
    }

    for(int i=0; i<n; i++){
        if(arr[i]>=0){
            Idxarr[arr[i]]=1;
        }
    }

    for(int i=1; i<N; i++){
        if(Idxarr[i]==0){
            cout << i <<endl;
            return 0;
        }

    }

    return 0;

}