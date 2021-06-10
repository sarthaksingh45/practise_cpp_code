#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
    int n,k;
    cin >>n >> k;
    vector<int> a(n);

    for(auto &i:a)
        cin>>i;
    vector<int> ans;
    deque<int> que;
    for(int i=0; i<k; i++){
        while(!que.empty() && a[que.back()]<a[i]){
            que.pop_back();
        }
        que.push_back(i);
    }
    ans.push_back(a[que.front()]);
    for(int i =k; i<n; i++){
        if(que.front() == (i-k)){
            que.pop_front();
        }
        while(!que.empty() && a[que.back()]<a[i]){
            que.pop_back();
        }
        que.push_back(i);
        ans.push_back(a[que.front()]);
    }
    
    for(auto i:ans) 
      cout<<i<<" ";

    return 0;
}