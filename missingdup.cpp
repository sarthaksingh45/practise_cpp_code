#include <iostream>
using namespace std;

int main(){
    int arr1[] = {1,2,4,5,3,6,7};
    int arr2[] = {1,4,3,2,6,7,5,8};

    int arr1ele[100]={0};
    int arr2ele[100]={0};
    for(int i=0; i<7; i++){
        arr1ele[arr1[i]]= 1;
    }

    for(int i=0; i<8; i++){
        arr2ele[arr2[i]] = 1;
    }

    for(int i=0; i<100 ; i++){
        if((arr1ele[i] == 1 && arr2ele[i] == 0) || (arr1ele[i] == 0 && arr2ele[i]== 1)){
            cout << i;
        }
    }

    return 0;

}