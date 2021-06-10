#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i].first >> arr[i].second;
        }
        int l,p;
        cin >> l >> p;

        for(int i=0; i<n ; i++){
            arr[i].first = l - arr[i].first;
        }
        sort(arr.begin(), arr.end(), [&](pair<int,int> &a, pair<int,int> &b){
            return a.first < b.first;
        });

        priority_queue<int, vector<int>> maxheap;
        
        int stop = 0, dist = p; 
        bool flag = 0;
        for(int i=0; i<n; i++){
            if(dist > l){
                break;
            }
            while(dist < arr[i].first){
                if(maxheap.empty()){
                    flag = 1;
                    break;
                }
                dist += maxheap.top();
                maxheap.pop();
                stop++;
            }
            if(flag){
                break;
            }
            maxheap.push(arr[i].second);
        }
        while(dist < l && !maxheap.empty()){
            dist += maxheap.top();
            maxheap.pop();
            stop++;
        }
        if(flag){
            cout << "-1";
            break;
        }
        else{
            cout << stop;
            break;
        }
    }
}

