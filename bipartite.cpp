#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> col;
bool bipart;

void color(int vertex, int c){
    if(visited[vertex]){
        if(col[vertex] != -1 and col[vertex] != c){
            bipart = false;
            return;
        }
    }
    if(!visited[vertex]){
        visited[vertex] = 1;
        col[vertex] = c;
        for(auto i: adj[vertex]){
            color(i, c xor 1);
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    adj = vector<vector<int>>(n);
    visited = vector<bool>(n,0);
    col = vector<int> (n,-1);
    bipart = true;

    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            color(i,0);
        }
    }

    if(bipart) cout <<"Bipartite";
    else cout <<" Not Bipartite";

    return 0;
}