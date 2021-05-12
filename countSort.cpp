#include <iostream>
using namespace std;

void countSort(int arr[], int n){
    int k=0;
    for(int i=0; i<n; i++){
        k=max(k,arr[i]);
    }

    int countArr[10]={0};

    for(int i=0; i<n; i++){
        countArr[arr[i]]++;
    }

    for(int i=1; i<=k; i++){
        countArr[i] += countArr[i-1];
    }

    int outputArr[n];

    for(int i=n-1; i>=0; i--){
        outputArr[--countArr[arr[i]]] = arr[i]; 
    }

    for(int i=0; i<n; i++){
        arr[i] = outputArr[i];
    }


}

int main(){
    int array[]={1,5,2,8,2,4,1,3,2};
    countSort(array, 9);
    for(int i=0; i<9; i++){
        cout << array[i] << " ";
    }
    return 0;
}