#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<int>> arr(n);
    // for(int i=0; i<n; i++){
    //     int a,b;
    //     cin >> a >> b;
    //     vector<int> temp = {a,b};
        
    //     arr.push_back(temp);
    // }

    for(int i=0; i<n; i++){
        arr[i] = vector<int>(2);
        cin >> arr[i][0] >> arr[i][1];
    }

    sort(arr.begin(), arr.end(), [&](vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    });

    for(auto it:arr){
        for(auto i:it){
            cout << i <<" ";
        }
        cout << endl;
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<2; j++){
    //         cout << arr[i][j] <<" ";
    //     }
    //     cout << endl;
    // }

    int take =1;
    int end = arr[0][1];

    for(int i=1; i<n; i++){
        if(arr[i][0]>= end){
            take++;
            end = arr[i][1];
        }
    }

    cout << take;

    return 0;
}