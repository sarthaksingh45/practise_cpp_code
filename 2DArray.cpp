#include <bits/stdc++.h>
using namespace std;

// Matrix Transpose of a Square matrix
// int main(){

//     int n,m;
//     cin >> n >> m;
//     int arr[n][m];

//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             cin >> arr[i][j];
//         }
//     }

//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<m; j++){
//             int temp;
//             temp=arr[i][j];
//             arr[i][j]=arr[j][i];
//             arr[j][i]=temp;


//         }
//     }

//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//Matrix Multiplication
int main(){

    int n,m,k;
    cin >> n >> m >> k;
    int a1[n][m];
    int a2[m][k];
    int a3[n][k];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a1[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<k; j++){
            cin >> a2[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            a3[i][j]=0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            
            for(int l=0; l<m; l++){
                
                a3[i][j] += a1[i][l]*a2[l][j];
            }
            
            
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cout << a3[i][j] <<" ";
        }
        cout << endl;
    }
    return 0;
}

