#include <iostream>
#include <vector>
using namespace std;

bool isCycle(int present, vector<vector<int>> &adj, vector<bool> &visited, int src){
    vector<int> :: iterator it;
    visited[present] = 1;
    for(it = adj[present].begin(); it != adj[present].end(); it++){
        if(*it != src){
            if(visited[*it]){
                return true;
            }
            if(!visited[*it] and isCycle(*it, adj, visited, present)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);

    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> visited(n,false);
    bool cycle = 0;

    for(int i=0; i<n; i++){
        if(!visited[i] and isCycle(i,adj, visited, -1)){
            cycle = 1;
        }
    }
    if(cycle) cout << "Cycle Present";
    else cout << "No Cycle";

    return 0;
}