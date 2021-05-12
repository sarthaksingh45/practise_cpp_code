#include <iostream>
using namespace std;

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a]= arr[b];
    arr[b] = temp;
}

void dnfSort(int arr[], int n){
    int mid=0;
    int low=0;
    int high = n-1;

    while(mid<high){
        if(arr[mid] == 0){
            swap(arr,low,mid);
            mid++; low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr,high,mid);
            high--; 
        }
    }
}

int main(){
    int arr[]= {1,0,2,1,0,0,1,2,2,0};
    dnfSort(arr,10);

    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }

    return 0;
}