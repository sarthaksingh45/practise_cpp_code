#include <iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int n){
    for(int i=0; i<x; i++){
        if(arr[i][y]==1){
            return false;
        }
    }

    int row=x;
    int col=y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }

        row--;
        col--;
    }

    row=x;
    col=y;
    while(row>=0 && col<n){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }

    return true;
}

bool nQueen(int** arr, int n, int row, int col){
    if(row>=n){
        
        return true;
    }


    for(int i=0; i<n; i++){
        if(isSafe(arr,row,i,n)){
            arr[row][i]=1;
            if(nQueen(arr,n,row+1,col)){
                return true;
            }
            arr[row][i]=0;

        }
    }
    return false;


}

int main(){
    int n;
    cin >> n;

    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++){
            arr[i][j]=0;
        }
    }

    if(nQueen(arr,n,0,0)){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    }


    return 0;


}