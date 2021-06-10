#include <bits/stdc++.h>
using namespace std;

void change(vector<vector<char>> &ar, int x, int y){
    ar[x][y] = '*';
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
    for(int i=0; i<4; i++){
        int cx = x+dx[i];
        int cy = y+dy[i];
        if(cx>= 0 and cx <ar.size() and cy>=0 and cy<ar[0].size()){
            if(ar[cx][cy] == 'O'){
                change(ar,cx,cy);
                //cout << cx << " " << cy << endl;
            }
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<char>> arr(n,vector<char> (m));
    for(int i=0 ; i<n ;i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 || i == n-1 || j == 0 || j == n-1){
                if(arr[i][j] == 'O'){
                    change(arr,i,j);
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 'O'){
                arr[i][j] = 'X';
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == '*'){
                arr[i][j] = 'O';
            }
        }
    }
    cout << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j] <<" "; 
        }
        cout << endl;
    }

    return 0;
}