#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    int array[N];

    for( int i=0; i<N; i++){
        cin >> array[i];
    }

    int num= 1e5+2;
    int countarr[num];

    for(int i=0; i<num; i++){
        countarr[i]=0;

    }
    for(int i=0; i<N; i++){
        countarr[array[i]]++;
    }

    int maxcount=INT_MIN;
    int countsumarr[num+1];
    countsumarr[num]=0;

    for(int i=0; i<num; i++){
        countsumarr[i]=countarr[i];

    }
    for(int i=num; i>0; i--){
        countsumarr[i] += countsumarr[i+1];
    }

    for(int i=0; i<num; i++){
        if((countsumarr[i]-countarr[i])>=K){
            maxcount= max(maxcount, countarr[i]+K);
        }
        else{
            maxcount= max(maxcount, countsumarr[i]);
        }
    }

    cout << maxcount <<endl;
    return 0;
}