#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> g(n+1);
    vector<int> dist(n+1,int(1e7+2));
    
    for(int i=0; i<m; i++){
        int u, v, w; cin >> u >> v >>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }


    int source; cin >> source;
    dist[source] = 0;

    set<pair<int,int>> s;
    s.insert({0, source});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        for(auto it: g[x.second]){
            if(dist[it.first] > dist[x.second] + it.second){
                s.erase({dist[it.first],it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first],it.first});
            }
        }
    }

    for(int i=1; i<n+1; i++){
        if(dist[i] < int(1e6+2)){
            cout << dist[i] <<" ";
        }
        else cout << -1 <<" ";
    }

    return 0;
}