#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
    int n; cin>> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int prefSum =0;
    map<int,int> m;
    for(int i=0; i<n; i++){
        prefSum += arr[i];
        m[prefSum]++;
    }

    int ans = 0;
    map<int,int> :: iterator it;
    for(it = m.begin(); it!=m.end(); it++){
        
        ans += ((it->second)*((it->second) - 1)/2);
        if(it->first == 0){
            ans += it->second;
        }
    }

    cout << ans;

    return 0;
}