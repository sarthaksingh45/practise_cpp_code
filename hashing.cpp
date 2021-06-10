#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    unordered_map<int,int> freq;
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }

    unordered_map<int,int> :: iterator it;
    for(it = freq.begin(); it!= freq.end(); it++){
        cout << it->first <<" : " << it->second;
        cout << endl;
    }

    return 0;
}