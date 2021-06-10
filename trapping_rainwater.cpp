#include <iostream>
#include <deque>
using namespace std;

int rainwaterArea(int* arr,int size){
    int area =0 ;
    int lowPtr=0,highPtr = size-1;
    int ll =0, rh =0;
    while(lowPtr<=highPtr){
        if(arr[lowPtr]<arr[highPtr]){
            if(arr[lowPtr]>ll){
                ll  = arr[lowPtr];
            }
            else{
                area += (ll-arr[lowPtr]);
            }
            lowPtr++;
        }
        else{
            if(arr[highPtr]>rh){
                rh = arr[highPtr];
            }
            else{
                area += (rh-arr[highPtr]); 
            }
            highPtr--;
        }
    }
    return area;
}

int main(){
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << endl;
    cout << rainwaterArea(arr, 12);

    return 0;
}