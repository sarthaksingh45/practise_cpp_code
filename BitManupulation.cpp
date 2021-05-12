#include <iostream>
using namespace std;

// int getDigit(int n, int pos){
//     return ((n & (1 << pos))!=0);
// }

// int setBit(int n, int pos){
//     return (n | (1 << pos));
// }

// int ResetBit(int n, int pos){
//     return (n & (~(1 << pos)));
// }

// int updateBit(int n, int pos, int value){
//     n = n & ( ~(1 << pos));
//     return (n | (value << pos));
// }
// int main(){
//     cout << updateBit(5,0,0) << endl;
//     return 0;
// }

// void uniqueNo(int arr[], int n){
//     int xorsum=0;
//     for(int i=0; i<n; i++){
//         xorsum = xorsum ^ arr[i];
//     }
//     cout << xorsum << endl;
// }

// int main(){
//     int arr[]={1,2,4,3,7,4,1,2,3};
//     uniqueNo(arr,9);
//     return 0;
// }

// int getBit(int n,int pos){
//     return ((n &(1 << pos))!=0);
// }

// void uniqueNos(int arr[], int n){
//     int xorsum=0;
//     for(int i=0; i<n; i++){
//         xorsum = xorsum ^ arr[i];
//     }
//     int tempxor= xorsum;
//     int setbit=0;
//     int pos=0;
//     while(setbit!=1){
//         setbit = getBit(xorsum, 0);
//         pos++;
//         xorsum = xorsum >> 1;
//     }
//     pos--;
//     int newxor=0;
//     for(int i=0; i<n; i++){
//         if(getBit(arr[i],pos)==1){
//             newxor = newxor^arr[i];
//         }
//     }
//     cout << newxor << endl;
//     cout << (newxor ^ tempxor) << endl;
// }

// int main(){
//     int arr[]={1,2,3,1,2,3,8,0};
//     uniqueNos(arr,8);
//     return 0;
// }
int getBit(int n, int pos){
    return ((n & (1 << pos))!=0);
}
int update(int number, int pos, int value){
    number = (number & (~(1 << pos)));
    return (number | (value << pos));
}

void uniqueNo(int arr[], int n){
    int answer=0;
    for(int i=0; i<64; i++){
        int sum=0;
        for(int j=0; j<n; j++){
            if(getBit(arr[j],i)){
                sum++;
            }
            
        }
        sum = sum%3;
        answer = update(answer,i,sum);
    }

    cout << answer << endl;
}

int main(){
    int arr[]={1,2,3,9,1,2,3,1,2,3};
    uniqueNo(arr,10);
    return 0;
}

