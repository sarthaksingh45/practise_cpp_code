#include<iostream>
#include<stack>
using namespace std;

int* solutionArr(int* arr, int size){
    stack<int> stk;
    int* solArr = new int[size];
    solArr[0] = 1;
    stk.push(0);

    for(int i =1 ; i<size; i++ ){
        while(!stk.empty() && arr[stk.top()]<=arr[i]) stk.pop();
        solArr[i] = stk.empty() ? i+1 : (i -stk.top());
        stk.push(i);
    }

    return solArr;

}

int main(){
    int arr[]= {100, 80, 60, 70, 60, 75, 85};
    int* solArr = solutionArr(arr, 7);
    for(int i=0 ; i<7; i++)
        cout << solArr[i];
    return 0;
}