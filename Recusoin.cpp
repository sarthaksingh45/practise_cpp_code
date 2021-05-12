#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int i, int key){
    if(i == n){
        return -1;
    }

    else if(key==arr[i])
        return i;

    else return firstOcc(arr, n, i+1, key);

}

int lastOcc(int arr[], int n, int i, int key){
    if(i == n) return -1;
    int index = lastOcc(arr, n, i+1, key);
    if( index !=(-1) ) return index;
    if(key == arr[i]) return i;
    return -1;

}

int main(){
    int n;
    cin >> n;
    int array[n];
    for(int i=0; i<n; i++){
        cin >> array[i];

    }

    int k;
    cin >> k;

    cout << firstOcc(array, n, 0, k) << " " << lastOcc(array, n, 0, k)<<endl;
    return 0;
}