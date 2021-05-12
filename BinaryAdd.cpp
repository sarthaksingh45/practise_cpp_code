#include <bits/stdc++.h>
using namespace std;

int reverse(int x){
    int rev=0;
    while(x>0){
        int lastDigit=x%10;
        rev=rev*10 +lastDigit;
        x/=10;
    }
    return rev;
}

int binaryAdd(int a,int b){
    int ans=0;
    int prevCarry=0;
    while(a>0 && b>0){
        if(a%10==0 && b%10==0){
           ans = ans*10 + prevCarry;
           prevCarry=0;

        }
        if((a%10==0 && b%10==1)||(a%10==1 && b%10==0)){
            if(prevCarry==0){
                ans = ans*10 + 1;
                
            }
            else{
                ans = ans*10 + 0;
                prevCarry=1;
            }
        }
        if(a%10==1 && b%10==1){
            ans= ans*10 + prevCarry;
            prevCarry=1;
        }
        a/=10;
        b/=10;


    }
    while(a>0){
        int lastDigit=a%10;
        if(prevCarry==0){
                ans= ans*10 +lastDigit;
        }
        if(prevCarry==1 && lastDigit==0){
            ans = ans*10 + 1;
            prevCarry=0;
        }
        if(prevCarry==1 && lastDigit==1){
            ans = ans*10 + 0;
            prevCarry =1;
        }
        a/=10;

    }
    while(b>0){
        int lastDigit=b%10;
        if(prevCarry==0){
                ans= ans*10 +lastDigit;
        }
        if(prevCarry==1 && lastDigit==0){
            ans = ans*10 + 1;
            prevCarry=0;
        }
        if(prevCarry==1 && lastDigit==1){
            ans = ans*10 + 0;
            prevCarry =1;
        }
        b/=10;

    }
    if(prevCarry==1){
        ans = ans*10 + 1;
    }

    ans=reverse(ans);
    return ans;


}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<binaryAdd(a,b)<<endl;
}