#include <bits/stdc++.h>
using namespace std;

int zero[100] ={0}, one[100] = {0};


int main(){
    int n; cin >> n;

    zero[1] = 1;
    one[1] = 1;
    for(int i = 2; i<n+1; i++){
        one[i] = zero[i-1];
        zero[i] = one[i-1] + zero[i-1];
    }
    cout << one[n] + zero[n];
    return 0;
}