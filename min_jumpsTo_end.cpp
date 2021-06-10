#include <bits/stdc++.h>
using namespace std;

// int main(){
//     int n; cin>> n;
//     int arr[n];
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }

//     int jumps = 1;
//     int st = 0;
//     int end = arr[0];
//     while(end<n){
//         int low = st, high = end;
//         for(int i=low; i<=high; i++){
//             if(i+arr[i] > end){
//                 end = i + arr[i];
//                 st = i;
//             }
//         }
//         cout << end << endl;
//         jumps++;
//     }
//     cout << jumps;

//     return 0;
// }


const int INF = 1e9;

int main(){
    int n ; cin >> n;
    int arr[n];
    for(auto &i: arr)
        cin >> i;
    
    int jumps[n];
    for(int i=0; i<n; i++)
        jumps[i] = INF;
    
    jumps[0] = 0;
    if(arr[0] == 0){
        cout << "Impossible";
        return 0;
    }

    for(int i=1; i< n; i++){
        for(int j = 0; j<i; j++){
            if(i<= (j+arr[j])){
                jumps[i] = min(jumps[i], jumps[j] + 1);
            }
        }
    }

    cout << jumps[n-1];
    return 0;
}