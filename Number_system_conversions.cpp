#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(int n){
    int ans=0;
    int x=1;
    while(n>0){
        int lastdigit=n%10;
        ans += x*lastdigit;
        x*=2;
        n/=10;
    }
    return ans;
}

int hexaTodecimal(string s){
    int ans=0;
    int x=1;
    int len=s.size();
    for(int i=len-1;i>=0;i--){
        if(s[i]>='0'&& s[i]<='9'){
            
            ans = ans + x*(s[i]-'0');


        }
        else if(s[i]>='A'&&s[i]<='F'){
            ans=ans + x*(s[i]-'A'+10);
        }
        x*=16;
    }
    return ans;

}

int decimalToBinary(int n){
    int ans=0;
    int x=1;
    while(x<=n)
         x*=2;
    x/=2;

    while(x>0){
        int lastdigit=n/x;
        ans= ans*10 +lastdigit;
        n-=x*lastdigit;
        x/=2;
    }
    return ans;


}

int decimalToOctal(int n){
    int ans=0;
    int x=1;
    while(x<=n)
         x*=8;
    x/=8;

    while(x>0){
        int lastdigit=n/x;
        ans= ans*10 +lastdigit;
        n-=x*lastdigit;
        x/=8;
    }
    return ans;


}

string decimalToHexa(int n){
    string ans="";
    int x=1;
    while(x<=n){
        x*=16;
    }
    x/=16;
    while(x>0){
        int lastdigit=n/x;
        if(lastdigit<=9){
            ans= ans+ to_string(lastdigit);
        }
        else{
            char c='A'+lastdigit-10;
            ans.push_back(c);
        }
        
        n-=x*lastdigit;
        x/=16;
    }
    return ans;

}

int main(){
    int n;
    cin>>n;
    cout<<decimalToHexa(n)<<endl;

}