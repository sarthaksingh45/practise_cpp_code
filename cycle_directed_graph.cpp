#include <iostream>
#include <vector>
using namespace std;

bool isCycle(int present, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &stk){
    visited[present] = 1;
    stk[present] = 1;

    for(auto i: adj[present]){
        if(stk[i]){
            return true;
        }
        if(!visited[i] and isCycle(i,adj,visited, stk)){
            return true;
        }
    }
    stk[present] = false;
    return false;
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<int> stk(n,0);
    vector<bool> visited(n, 0);
    bool cycle = 0;

    for(int i=0; i<n; i++){
        if(!visited[i] and isCycle(i, adj, visited, stk)){
            cycle = 1;
        }
    }
    if(cycle){
        cout << "Cycle Present";
    }else{
        cout << "No cycle";
    }

    return 0;
}