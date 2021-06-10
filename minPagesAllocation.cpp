#include <iostream>
#include <climits>
using namespace std;

bool isFeasible(int arr[], int n, int m, int min){
    int sum = 0;
    int studentAllo = 1;
    for(int i=0; i<n; i++){
        if(arr[i]>min){
            return false;
        }
        if(sum+arr[i]>min){
            studentAllo++;
            sum = arr[i];
            if(studentAllo>m){
                return false;
            }
        }
        else{
            sum += arr[i];
        }
    }
    return true;
}

int minPagesAllo(int arr[], int n, int m){
    if(n<m){
        return -1;
    }
    int sum =0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    int start = 0, end = sum, result = INT_MAX;
    while(start < end){
        int mid = (start+end)/2;
            cout << mid <<endl;
        if(isFeasible(arr,n,m,mid)){
            result = min(result, mid);
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    } 
    return result;
}

int main(){
    int arr[] = {10,20,30,40};
    cout << minPagesAllo(arr,4,2);

    return 0;
}