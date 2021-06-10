#include <bits/stdc++.h>
using namespace std;

// const int N = 1e3;
// int dp[N][N];

// int ways(vector<int> &ar, int n, int val){
//     if(val == 0){
//         return 1;
//     }
//     if(val < 0){
//         return 0;
//     }
//     if(n <= 0){
//         return 0;
//     }

//     if(dp[n][val] != -1){
//         return dp[n][val];
//     }
    
//     dp[n][val] = ways(ar, n, val - ar[n-1]) + ways(ar, n-1, val);
//     return dp[n][val];
// }

// int main(){
//     int n; cin >> n;
//     vector<int> coins(n); 
//     for(int i=0; i<n; i++){
//         cin >> coins[i];
//     }

//     for(int i=0; i<N; i++){
//         for(int j=0; j<N; j++){
//             dp[i][j] = -1;
//         }
//     }

//     int val; cin >> val;

//     cout << ways(coins,n, val);

//     return 0;
// }

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int x; cin >> x;

    vector<vector<int>> dp(n+1, vector<int> (x+1,0));

    dp[0][0] = 1;

    for(int i=1; i<n+1; i++){
        for(int j=0; j<x+1; j++){
            if(j-arr[i-1] >= 0){
                dp[i][j] += dp[i][j-arr[i-1]];
            }
            dp[i][j] += dp[i-1][j];
        }
    }

    cout << dp[n][x];

    return 0;
}