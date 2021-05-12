#include <iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j] =temp;
}

int partition(int arr[],int low, int high){
    int pivot= arr[high];
    int i=low-1;
    int j=low;
    while(j<high){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
        j++;
    }
    swap(arr,i+1,high);
    return i+1;
}

void quickSort(int arr[],int low, int high){
    if(low<high){
        int p =partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}

int main(){
    int arr[] = {0,2,6,1,8,3};
    quickSort(arr,0,5);
    for(int i=0; i<6; i++){
        cout << arr[i] <<" ";
    }
}