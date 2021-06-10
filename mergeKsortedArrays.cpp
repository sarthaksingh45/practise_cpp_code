#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<int>> arr(n);

    for(int i=0; i<n; i++){
        int k; cin >> k;

        arr[i] = vector<int>(k);
        for(int j=0; j<k; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> idx(n,0);

    priority_queue<pair<int,int>, vector<pair<int , int>>, greater<pair<int,int>>> pq;
    for(int i=0; i<n; i++){
        pair<int,int> temp;
        temp.first = arr[i][0];
        temp.second = i;
        pq.push(temp);
    }

    vector<int> ans;

    while(!pq.empty()){
        pair<int,int> topEle = pq.top();
        pq.pop();
        ans.push_back(topEle.first);
        idx[topEle.second]++;
        if(idx[topEle.second] < arr[topEle.second].size()){
            pair<int,int> toBePush;
            toBePush.first = arr[topEle.second][idx[topEle.second]];
            toBePush.second = topEle.second;
            pq.push(toBePush);
        }
    }

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] <<" ";
    }

    return 0;
}