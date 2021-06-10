#include <bits/stdc++.h>
using namespace std;

const int N= 1e5 + 6;
vector<int> parent(N,-1);
int size[N];

void make_set(int val){
    parent[val] = val;
    size[val] = 1;
}

int find_set(int a){
    if(a == parent[a]){
        return a;
    }
    if(parent[a] == -1){
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
    // for(int i=0; i<N; i++){
    //     make_set(i);
    // }
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(m);
    for(int i=0; i<m; i++){
        int x,y, w; cin >> x >> y >> w;
        adj[i] = {w,x,y};
    }

    sort(adj.begin(), adj.end());
    int weight =0;

    for(auto i: adj){
        int a = i[1];
        int b = i[2];
        int r = find_set(a);
        int q = find_set(b);
        if(r == q){
            continue;
        }
        else{
            cout << a <<" " << b << endl;
            weight += i[0];
            union_set(a,b);
        }
    }
    cout << weight;

    return 0;
}

