#include <iostream>
using namespace std;

// void permutate(string s, string ans)
// {
//     if (s.length() == 0)
//     {
//         cout << ans << endl;
//         return;
//     }

//     for (int i = 0; i < s.length(); i++)
//     {
//         char ch = s[i];
//         string ros = s.substr(0, i) + s.substr(i + 1);
//         permutate(ros, ans + ch);
//     }
// }

// int main(){
//     string q = "ABC";
//     permutate(q, "");
//     return 0;
// }

// int boardGame(int s, int e){
//     if(s == e){
//         return 1;
//     }

//     if(s>e) return 0;
//     int countSum=0;

//     for(int i=1; i<=6 ; i++){
//         countSum += boardGame(s+i,e);
//     }

//     return countSum;

// }

// int main(){
//     cout << boardGame(0,4) ;
//     return 0;
// }

// int maze(int n, int i, int j){

//     if((i == (n-1)) && (j == (n-1))) return 1;
//     if((i>=n )|| (j>=n)) return 0;

//     return maze(n,i+1,j) + maze(n,i,j+1);
// }

// int main(){
//     cout << maze(3,0,0);
//     return 0;
// }

// int tilling(int n){
//     if(n==0 || n==1) return n;
//     return tilling(n-1) + tilling(n-2);
// }

// int main (){
//     cout << tilling(4);
//     return 0;
// }

// int pairing(int n){

//     if(n==0 || n==1 || n==2){
//         return n;
//     }
//     return pairing(n-1) + (n-1)*pairing(n-2);
// }

// int main(){
//     cout << pairing(4);
//     return 0;

// }

int knapsack(int value[], int wt[], int n, int w)
{
    if (n == 0)
        return 0;

    if (wt[n - 1] > w)
        return knapsack(value, wt, n - 1, w);
    return max(knapsack(value, wt, n - 1, w - wt[n - 1]) + value[n - 1], knapsack(value, wt, n - 1, w));
}

int main(){
    int value[]= {100,50,150};
    int weight[]={10,20,30};
    cout << knapsack(value,weight,3,50);
    return 0;
}