#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int dp[100][100];

int optimal(int i, int j){
    if(i == j)
        return arr[i];
    
    if(i>j)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int l = arr[i] + min(optimal(i+2, j), optimal(i+1, j-1));
    int r = arr[j] + min(optimal(i,j-2), optimal(i+1, j-1));
    return dp[i][j] = max(l,r);
}

int main(){
    memset(dp, -1, sizeof dp);
    int n; cin >> n;
    arr = vector<int> (n);
    for(auto &i: arr)
        cin >> i;

    cout << optimal(0, n-1);
    
    return 0;
}