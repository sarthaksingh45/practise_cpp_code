#include <iostream>
using namespace std;

int merge(int arr[], int low, int mid, int high){
    int inv=0;
    int n1 = mid-low+1;
    int n2 = high-mid;

    int a[n1]; int b[n2];
    for(int i=0; i<n1; i++){
        a[i] = arr[low+i];
    }
    for(int i=0; i<n2; i++){
        b[i] = arr[mid+1+i];
    }

    int i=0,l=0,k=low;


    while(i<n1 && l<n2){
        if(a[i]<=b[l]){
            arr[k]=a[i];
            i++;k++;
        }
        else{
            arr[k]=b[l];
            inv += n1-i;
            k++;l++;
        }
    }

    while(i<n1){
        arr[k]= a[i];
        i++;k++;
    }
    while(l<n2){
        arr[k]= b[l];
        k++;l++;
    }

    return inv;
}

int mergeSort(int arr[],int low, int high){
    int inv=0;

    if(low<high){
        int mid =(low+high)/2;
        inv += mergeSort(arr,low,mid);
        inv += mergeSort(arr,mid+1,high);
        inv += merge(arr,low,mid,high);
    }

    return inv;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << mergeSort(arr,0,n-1) <<endl;

    for(int i=0 ; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}