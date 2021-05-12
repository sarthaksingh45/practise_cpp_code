#include <bits/stdc++.h>
using namespace std;

int linearSearch(int array[],int n, int key){
    for(int i=0;i<n;i++){
        if(array[i]==key){
            return i;
        }
    }
    return -1;
}

int binarySearch(int array[], int n, int key){
    int startingIndex=0;
    int endingIndex=n-1;
    while(startingIndex<=endingIndex){
        int mid=(startingIndex+endingIndex+1)/2;
        if(array[mid]==key){
            return mid;
        }
        else if(array[mid]>key){
            endingIndex=mid-1;
        }
        else{
            startingIndex=mid+1;
        }
    }
    return -1;
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;

    cout<<binarySearch(arr,n,key);
}