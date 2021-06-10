#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;

int val[N], wt[N];
int dp[N][N];

int knapsack(int n, int w){
    if(n <= 0){
        return 0;
    }

    if(w<=0)
        return 0;
    
    if(wt[n-1] > w){
        return knapsack(n-1, w);
    }

    if(dp[n][w] != -1){
        return dp[n][w];
    }

    dp[n][w]  = max(knapsack(n-1, w) , knapsack(n-1, w-wt[n-1]) + val[n-1]);
    return dp[n][w];
}

int main(){
    int n; cin >> n;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dp[i][j] = -1;
        }
    }

    for(int i=0; i<n; i++){
        cin >> val[i];
    }
    for(int i=0; i<n; i++){
        cin>> wt[i];
    }

    int w; cin >> w;

    cout << knapsack(n, w);

    return 0;
}