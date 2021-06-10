#include<iostream>
#include <algorithm>
using namespace std;

bool findSum(int* arr, int size, int sum){
    sort(arr,(arr+size));
    int head,end;
    for(int i=0; i<size; i++){
        head = i+1, end = size -1;
        while(head<end){
            if(arr[i]+arr[head]+arr[end] < sum){
                head++;
            }
            else if(arr[i]+arr[head]+arr[end]==sum){
                cout << arr[i] <<" " << arr[head] << " " << arr[end];
                return true;
            }
            else{
                end--;
            }
        }
    }
    return false;
}

int main(){
    int arr[]={12, 3, 4, 1, 6, 9};
    cout << findSum(arr, 6, 23);
    return 0;
}