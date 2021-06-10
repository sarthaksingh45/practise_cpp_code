#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int> (n,0));
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        arr[x-1][y-1] = 1;
        arr[y-1][x-1] = 1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}