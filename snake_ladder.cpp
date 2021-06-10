#include <bits/stdc++.h>
using namespace std;

int main(){
    int ladders, snakes; cin >> ladders;
    map<int, int> lad;
    map<int, int> snak;
    for(int i=0; i<ladders; i++){
        int x, y; cin >> x >> y;
        lad[x] = y;
    }

    cin >> snakes;
    for(int i=0 ;i<snakes; i++){
        int x, y; cin >> x >>y;
        snak[x] = y;
    }

    queue<int> q;
    q.push(1);
    bool found = 0;
    int moves =0;
    vector<int> vis(101, 0);
    while(!q.empty() and !found){
        int sz = q.size();
        while(sz--){
            int t= q.front();
            q.pop();
            for(int die=1; die<=6; die++){
                if(t+die == 100){
                    found = true;
                    break;
                }
                else if(t+die<=100 and lad[t+die] and !vis[t+die]){
                    vis[lad[t+die]] =true;
                    q.push(lad[t+die]);
                }
                else if(t+die <= 100 and snak[t+die] and !vis[t+die]){
                    vis[snak[t+die]] = true;
                    q.push(snak[t+die]);
                }
                else if(t+die <= 100 and !lad[t+die] and !snak[t+die] and !vis[t+die]){
                    vis[t+die] = true;
                    q.push(t+die);
                }
            }
        }
        moves++;
    }

    if(found)
        cout << moves;
    else 
        cout <<"-1";
    
    return 0;
}