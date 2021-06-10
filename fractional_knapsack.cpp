#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    int n; cin >> n;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    int w; cin >> w;

    sort(arr.begin(), arr.end(), [&](pair<int,int> &a, pair<int,int> &b){
        double v1 = (double)a.first/a.second;
        double v2 = (double)b.first/b.second;
        return v1 > v2;
    });

    int ans=0;

    for(int i=0; i<n; i++){
        if(w>=arr[i].second){
            ans += arr[i].first;
            w -= arr[i].second;
            continue;
        }
        double val = (double)arr[i].first/arr[i].second;
        ans += w*val;
        w = 0;
        break;
    }

    cout << ans;
    return 0;
}