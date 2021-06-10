#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> adj[n];
    int indg[n] = {0};

    for(int i=0; i<m ; i++){
        int x,y; cin >> x>> y;
        adj[x-1].push_back(y-1);
        indg[y-1]++;
    }

    queue<int> que;
    for(int i = 0; i<n; i++){
        if(indg[i] == 0){
            que.push(i);
        }
    }

    while(!que.empty()){
        int node = que.front();
        que.pop();
        cout << node + 1 << " ";
        vector<int> :: iterator it;
        for(it = adj[node].begin(); it != adj[node].end(); it++){
            indg[*it]--;
            if(indg[*it] == 0){
                que.push(*it);
            }
        }
    }

    return 0;

}