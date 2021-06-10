#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(4);
    s.insert(5);

    for(auto i:s){
        cout << i << " ";
    }
    cout << endl;
    s.erase(s.find(2));
    s.erase(s.begin());
    // cout << *s.lower_bound(3) <<" ";
    // cout << *s.upper_bound(3) << " ";
    // cout << *s.lower_bound(4)<<" ";
    // cout << *s.upper_bound(5)<<" ";
    // cout << endl;
    for(auto i:s){
        cout << i << " ";
    }
    return 0;

}