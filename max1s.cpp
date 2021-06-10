#include <iostream>
#include <vector>
// #include <stack>
using namespace std;

// void maxOnes(int* arr, int size, int m){
//     // stack<int> stkZero, stkOne;
    
//     vector<int> zeroes,left,right;
//     for(int i=0; i<size; i++){
//         if(arr[i] == 0){
//             zeroes.push_back(i);
//         }
//     }
//     for(int i=0; i<zeroes.size(); i++){
//         cout << zeroes[i] <<" ";
//     }
//     cout <<endl;
//     for(int i=0; i<zeroes.size(); i++){
//        left.push_back(i==0?zeroes[i]:zeroes[i]-zeroes[i-1]-1);
//        right.push_back(i==zeroes.size()-1? size - zeroes[i]-1:zeroes[i+1]-zeroes[i]-1);
//     }
   
//     for(int i=0; i<zeroes.size(); i++){
//         cout << "left " << left[i] <<" Roght " <<right[i] <<endl;
//     }
//     cout << "Working" <<endl;
//     int totalOnes=0;
//     for(int i=0; i<zeroes.size(); i++){
//         int j=i;
//         int count =0;
//         do{
//             count+= left[j];
//             j++;
//         }while(j-i<m);
//         count += right[j-1];
//         count += m;
//         cout << count << endl;
//         totalOnes = max(totalOnes, count);
//     }
//     cout << totalOnes;
// }

// int main(){
//     int arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1};
//     maxOnes(arr,11,1);
//     return 0;
// }

void maxOnes(int* arr, int size, int m){
    int lowPtr = 0, highPtr = 0;
    int zeroCnt = 0;
    int windowSize = -1;
    int bestL, bestR;

    while(highPtr<size){
        if(zeroCnt<=m){
            highPtr++;
            if(arr[highPtr]==0){
                zeroCnt++;
            }
            
        }
        else{
            if(arr[lowPtr]==0){
                zeroCnt--;
            }
            lowPtr++;
        }

        if(highPtr-lowPtr>windowSize){
            windowSize = highPtr- lowPtr;
            bestL = lowPtr;
            bestR = highPtr;
        }

    }

    cout << windowSize <<" " << bestL << " " << bestR;
}

int main(){
    int arr[]= {1, 0, 0, 1, 1, 0, 1, 0, 1, 1};
    maxOnes(arr,10, 2 );
    return 0;
}