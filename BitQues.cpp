#include <iostream>
using namespace std;

// bool poweroftwo(int number){
//     if(number && !(number & (number-1)))
//         return 1;
//     else return 0;
// }

// int main(){
//     int num;
//     cin >> num;
//     cout << poweroftwo(num) << endl;
// }

// int noofone(int num){
//     int count=0;
//     while(num!=0){
//         num = (num & (num-1));
//         count++;
//     }
//     return count;
// }

// int main(){
//     int num;
//     cin >> num;
//     cout << noofone(num) << endl;
// }
int getBit(int number, int position){
    return ((number & (1 << position))!=0);
}

void printSubset(int arr[], int n){
    for(int i=0; i<(1 << n); i++){
        for(int j=0; j<n; j++){
            if(getBit(i,j)){
                cout << arr[j] <<" ";
            }
            
        }
        cout << endl;

    }
}

int main(){
    int array[]={1,2,3,4};

    printSubset(array, 4);
    return 0;
}