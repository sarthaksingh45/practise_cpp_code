#include <bits/stdc++.h>
using namespace std;

// const int N = 102;
// int a[N];
// int dp[N][N];

// int mcs(int i, int j){
//     if(i== j){
//         return 0;
//     }
//     if(dp[i][j] != -1)
//         return dp[i][j];
    
//     dp[i][j] = INT_MAX;

//     for(int k = i; k<j; k++){
//         dp[i][j] = min(dp[i][j], mcs(i,k) + mcs(k+1, j) + a[i-1]*a[k]*a[j]);
//     }
//     return dp[i][j];

// }

// int main(){
//     int n; cin >> n;

//     memset(dp, -1, sizeof dp);

//     for(int i=0; i<n; i++){
//         cin >> a[i];
//     }

//     cout << mcs(1, n-1);
//     return 0;
// }


int main(){
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int dp[n][n];
    for(int i=1; i<n; i++)
        dp[i][i] = 0;

    for(int l = 2; l<n; l++){
        for(int i=1; i<n-l+1; i++){
            int j = i+l-1;
            dp[i][j] = INT_MAX;
            for(int k = i; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
            }
        }
    }

    cout << dp[1][n-1];

    return 0;
}