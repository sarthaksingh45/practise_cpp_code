#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n, m;cin >> n >> m;
    vector<int> adj[n];
    bool visited[n] = {0};

    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> que;
    que.push(0);
    visited[0] = 1;
    while(!que.empty()){
        int node = que.front();
        que.pop();
        cout << node <<" ";
        vector<int> :: iterator it;
        for(it = adj[node].begin(); it != adj[node].end(); it++){
            if(!visited[*it]){
                que.push(*it);
                visited[*it] = 1;
            }
        }
    }

    return 0;
}