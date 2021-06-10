#include <iostream>
using namespace std;

int peakElement(int arr[], int low, int high, int n){
    int mid = low+(high-low)/2;
    if((mid==0 || arr[mid]>arr[mid-1]) && (mid == n-1 || arr[mid] > arr[mid+1])){
        return mid;
    }
    else if(arr[mid-1]>arr[mid]){
        return peakElement(arr,low,mid-1,n);
    }
    else{
        return peakElement(arr,mid+1,high,n);
    }
}

int main(){
    int arr[] = {10,20,3,6,7,9,8};

    cout << peakElement(arr,0,6,7);
    return 0;
}