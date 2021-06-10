#include <bits/stdc++.h>
using namespace std;

int getComp(int present, vector<vector<int>> &adj, vector<int> &visited){
    visited[present] = 1;

    int ans = 1;
    for(auto i:adj[present]){
        if(!visited[i]){
            ans += getComp(i, adj, visited);
        }
    }
    return ans;
}

int main(){
    int n, m; cin >> n>>m;
    vector<vector<int>> adj(n);
    vector<int> visited(n, 0);

    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> components;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            components.push_back(getComp(i,adj,visited));
        }
    }

    for(auto i:components){
        cout << i <<" ";
    }

    return 0;
}