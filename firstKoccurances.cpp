#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n,k; cin >> n >> k;
    vector<int> arr(n);

    for(int i=0; i< n; i++){
        cin >> arr[i];
    }

    map<int,int> m;
    for(int i=0; i<n; i++){
        if(m.size() == k && m[arr[i]]==0){
            break;
        }
        m[arr[i]]++;
    }
    int count =0;
    map<int,int> :: iterator it;
    for(it = m.begin(); it!= m.end(); it++){
        if(it->second == 0){
            break;
        }
        count += it->second;
    }
    for(int i=0; i<count; i++){
        cout << arr[i] <<" ";
    }

    return 0;
}