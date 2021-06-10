#include <iostream>
#include <vector>
#include <map>
using namespace std;

void helper(int r, int c, vector<vector<int>> &arr, map<pair<int,int>,map<int,int>> &m, vector<map<int,int>> &row, vector<map<int,int>> &col){
    if(r == 9){
        for(auto it:arr){
            for(auto i:it){
                cout <<i <<" ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    if(c == 9){
        helper(r+1, 0, arr, m, row, col);
        return;
    }
    if(arr[r][c] != 0){
        helper(r,c+1, arr,m ,row,col);
        return;
    }
    for(int i=1; i<=9; i++){
        int rw = r/3, cl = c/3;
        if(!m[{rw,cl}][i] and !row[r][i] and !col[c][i]){
            m[{rw,cl}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            arr[r][c] = i;
            helper(r,c+1, arr,m , row, col);
            m[{rw,cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            arr[r][c] = 0;
        }
    }
    
}

void sodukuSolver(vector<vector<int>> &arr){
    map<pair<int,int>,map<int,int>> m;
    vector<map<int,int>> row(9);
    vector<map<int,int>> col(9);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(arr[i][j] != 0){
                m[{i/3,j/3}][arr[i][j]] = 1;
                row[i][arr[i][j]] = 1;
                col[j][arr[i][j]] = 1;
            }
        }
    }

    helper(0,0,arr,m,row,col);

    // for(auto it: arr){
    //     for(auto i:it){
    //         cout << i <<" ";
    //     }
    //     cout << endl;
    // }
}

int main(){
    vector<vector<int>> sodoku = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    
    sodukuSolver(sodoku);



    return 0;
}