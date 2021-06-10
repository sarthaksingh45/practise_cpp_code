#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N = 1e5 +2;
vector<int> adj[N];
bool visited[N] = {0};

void dfs(int node){
    cout << node << " ";
    visited[node] = 1;

    vector<int> :: iterator it;
    for(it = adj[node].begin(); it != adj[node].end(); it++){
        if(!visited[*it]){
            dfs(*it);
        }
    }
}

int main(){
    int n; cin >> n;

    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);
}