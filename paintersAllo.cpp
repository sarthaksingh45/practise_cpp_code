#include <iostream>
using namespace std;

bool isFeasible(int arr[], int n, int m, int min){
    int count=0, painters=0;
    for(int i=0; i<n; i++){
        if(count + arr[i]>min){
            painters++;
            count = arr[i];
            if(painters>m){
                return true;
            }
        }
    }
    return false;
}

int timeToPaint(int arr[], int n, int m){
    int maxSize = 0, totalLength = 0;
    for(int i=0; i<n; i++){
        maxSize= max(maxSize, arr[i]);
        totalLength += arr[i];
    }
    //int test = 2;
    int low = maxSize, high = totalLength;
    int result=totalLength;
    while(low<high){
        int mid = (low+high)/2;
        if(isFeasible(arr,n,m,mid)){
            high = mid;
            cout << mid << endl;
            result = min(result, mid);
        }
        else{
            low = mid+1;
        }
    }
    return result;
}

int main(){
    int arr[]= {10,20,30,40};
    cout << "Time to paint is: "<<timeToPaint(arr,4,2);

    return 0;
}