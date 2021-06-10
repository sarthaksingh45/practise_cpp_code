#include <bits/stdc++.h>
using namespace std;

const int INF = 1e7 + 4;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> edges;
    for(int i=0; i<m; i++){
        int x ,y, w; cin >> x >> y >> w;
        edges.push_back({x,y,w});
    }
     
    int src; cin >> src;
    
    vector<int> dist(n, INF);
    dist[src] = 0;

    for(int i=0; i<n-1; i++){
        for(auto j:edges){
            int x = j[0];
            int y = j[1];
            int w = j[2];
            dist[y] = min(dist[y], dist[x] + w);
        }
    }

    for(int i=0; i<n; i++){
        cout << dist[i] <<" ";
    }

    return 0;
}