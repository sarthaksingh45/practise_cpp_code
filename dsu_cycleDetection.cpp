#include <bits/stdc++.h>
using namespace std;

const int N= 1e5 +6;
vector<int> parent(N);
vector<int> size(N);

void make_set(int val){
    parent[val] = val;
    size[val] = 1;
}

int find_set(int a){
    if(a == parent[a]){
        return a;
    }
    if(parent[a] == 0){
        make_set(a);
        return a;
    }
    return parent[a] = find_set(parent[a]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(size[a] < size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<int> adj[m+1];
    
    for(int i=1; i<m+1 ; i++){
        int x, y; cin >> x >> y;
        adj[i] = {x,y};
    }

    bool cycle = 0;
    for(int i=1; i<m+1; i++){
        int a = adj[i][0];
        int b = adj[i][1];
        int x = find_set(a);
        int y = find_set(b);
        if(x == y){
            cycle = 1;
            cout << x <<" " << y <<" ";
            cout << endl;
        }
        else{
            union_set(a,b);
        }
    }
    cout << endl;
    cout << parent[1] << endl;

    if(cycle) cout << "Cycle";
    else cout << "no cycle";

    return 0;
}