#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int Sum;
    cin >> Sum;
    int arr[n];
    for(int i=0;i<n; i++){
        cin >> arr[i];
    }

    

    
    int currS=0;

    int i=0,j=0,st=-1,en=-1;

    while(j<n && currS+arr[j]<=Sum ){
        currS += arr[j];

        j++;

    }
    
    if(currS==Sum){
        st=i+1;
        en=j+1;
        cout << st <<" " << en;
    }
    
    while(j<n){
        currS += arr[j];  
        
        while(currS>Sum){
            currS -= arr[i];
            i++;
        }
        if(currS==Sum){
            st=i+1;
            en=j+1;
            
            break;
        }
        
        j++;
        


    }
    cout << st << " " << en;
    return 0;

}