#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int main(){
//     vector<int> v;
//     v.push_back(3);
//     v.push_back(5);
//     v.push_back(8);

//     for(int i =0; i<v.size(); i++){
//         cout << v[i] <<" ";
//     }

//     cout <<endl;

//     vector<int>::iterator it;

//     for(it=v.begin(); it<v.end(); it++){
//         cout << *it <<" ";
//     }

//     cout << endl;

//     for(auto element:v){
//         cout << element <<" ";
//     }

//     vector<int> v2(3,100);
//     swap(v,v2);
//     cout << endl;

//     for(auto element:v){
//         cout << element <<" ";
//     }
//     cout << endl;
//     for(auto element:v2){
//         cout << element <<" ";
//     }
//     return 0;

// }

bool myCompare(pair<int, int> p1, pair<int,int> p2){
    return (p1.first<p2.first);
}

int main(){
    
    int arr[]={13,51,12,7,8,45,1,87};

    vector<pair<int,int>> v;

    for(int i=0; i<(sizeof(arr)/sizeof(arr[0])); i++){
        v.push_back(make_pair(arr[i],i));
    }

    for(auto elemnt:v){
        cout << elemnt.first << " "<< " ";
    }
    cout <<endl;

    
    sort(v.begin(), v.end(), myCompare);

    int n= (sizeof(arr)/sizeof(arr[0]));
    int* arr2 = new int[sizeof(arr)/sizeof(arr[0])];

    for(int i=0; i<n; i++ ){
        arr2[v[i].second]=i;
    }
    
    cout << endl;
     for(int i=0; i<n; i++ ){
        cout << arr2[i] << " ";
    }

    return 0;




}