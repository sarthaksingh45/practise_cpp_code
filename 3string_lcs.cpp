#include <bits/stdc++.h>
using namespace std;

int dp[200][200][200];

int lcs(string &s1, string &s2,string &s3, int n, int m, int o){
    if(n == 0 or m == 0 or o == 0){
        return 0;
    }

    if(dp[n][m][o] != -1)
        return dp[n][m][o];

    if(s1[n-1] == s2[m-1] and s2[m-1] == s3[o-1]){
        dp[n][m][o] = 1 + lcs(s1,s2,s3, n-1, m-1, o-1);
    }else{
    int l = lcs(s1,s2,s3, n-1, m, o);
    int p = lcs(s1,s2,s3, n, m-1, o);
    int q = lcs(s1,s2,s3, n, m, o-1);

    dp[n][m][o] = max({l,p,q});
    }
    return dp[n][m][o];
}

int main(){
    memset(dp, -1, sizeof dp);
    string s1, s2, s3; cin >> s1 >> s2 >> s3;

    cout << lcs(s1,s2,s3, s1.size(), s2.size(), s3.size());

    return 0;
}