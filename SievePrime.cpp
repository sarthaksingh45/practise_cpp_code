#include <iostream>
using namespace std;

// void SievePrime(int num){
//     int markArr[100]={0};

//     for(int i=2; i<num; i++){
//         for(int j=i*i; j<num; j+=i){
//             markArr[j]=1;
//         }
//     }

//     for(int i=2; i<num; i++){
//         if(markArr[i]==0){
//             cout << i <<" ";
//         }
//     }
// }
void PrimeFac(int n){
    int spf[100]={0};
    for(int i=2; i<=n; i++){
        spf[i] = i;
    }
    
    for(int i=2; i<n; i++){
        if(spf[i]==i){
            for(int j=i*i; j<=n; j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
        
    }

    while(n!=1){
        cout << spf[n] << " ";
        n /= spf[n];
    }
}

int main(){
    int num;
    cin >> num;
    PrimeFac(num);

    return 1;
}