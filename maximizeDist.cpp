#include <iostream>
#include<algorithm>
using namespace std;

bool isFeasible(int arr[], int mid, int n, int k){
    int element = 1;
    int first = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i]-first>=mid){
            element++;
            first = arr[i];
            if(element == k){
                return true;
            }
        }
    }
    return false;
}

void maxDist(int arr[], int n, int k){
    sort(arr,arr+n);
    int first = arr[0], last = arr[n-1];
    int result  = -1;
    while(first<last){
        int mid = (first+last)/2;
        if(isFeasible(arr,mid,n,k)){
            result = max(result,mid);
            first = mid + 1;
        }
        else{
            last = mid;
        }
    }

    cout << result ;
}

int main(){
    int arr[] = {1,2,8,4,9};
    maxDist(arr,5,2);

    return 0;
}