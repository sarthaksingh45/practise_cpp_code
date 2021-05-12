#include <bits/stdc++.h>
#include <climits>
using namespace std;

int kedane(int array[],int n){
        int sum=0;
        int maxSum=INT_MIN;
        for(int i=0; i<n; i++){
            sum += array[i];
            if(sum<=0){
                sum=0;
            }
            maxSum= max(sum,maxSum);
        }
        return maxSum;
    }


int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
/*  Brute Force Approach
    int maxSum=INT_MIN;
    for(int i=0; i<n; i++){
        
        for(int j=i; j<n; j++){
            int sum=0;
            for(int k=i; k<=j; k++){
                sum+=arr[k];
            }
            maxSum=max(maxSum,sum);


        }
    }
    cout << maxSum;
*/

/* cummulative Sum Approach
    int sumarr[n+1];
    sumarr[0]=0;
    for(int i=1; i<=n; i++){
        sumarr[i] = sumarr[i-1]+arr[i-1];

    }
    int maxSum=INT_MIN;
    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            int sum=0;
            sum = sumarr[i]-sumarr[j];
            maxSum= max(sum,maxSum);
        }
    }

    cout << maxSum;
*/

/* Kedanes Approach
    int sum=0;
    int maxSum=INT_MIN;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum<=0){
            sum=0;
        }
        maxSum= max(maxSum,sum);

    }

    cout<< maxSum;
*/
    
    int wrapsum;
    int unwrapsum;

    unwrapsum=kedane(arr,n);

    int arraySum=0;
    for(int i=0; i<n; i++){
        arraySum += arr[i];
    }

    for(int i=0; i<n; i++){
        arr[i]=-arr[i];
    }
    int NCsum=kedane(arr,n);
    wrapsum =arraySum+NCsum;

    cout << max(wrapsum,unwrapsum);



}