#include <iostream>
#include <stack>
using namespace std;

int largestAreaRect(int* arr, int size){
    // int* leftSideArr = new int[size];
    // int* rightSideArr = new int[size];
    // for(int i=0; i<size; i++){
    //     int leftPtr=1,rightPtr = 1;
    //     int j=i-1;
    //     while(j>=0 && arr[j]>=arr[i]){
    //         leftPtr++;
    //         j--;
    //     }
    //     leftSideArr[i] = leftPtr;
    //     j=i+1;
    //     while(j<size && arr[j]>=arr[i]){
    //         rightPtr++;
    //         j++;
    //     }
    //     rightSideArr[i] = rightPtr;
    // }
    // int maxArea =0 ;
    // for(int i =0; i<size; i++){
    //     maxArea = max(arr[i]*(leftSideArr[i]+rightSideArr[i]-1), maxArea);
    // }

    // for(int i=0; i<size; i++){
    //     cout << "leftArr " << leftSideArr[i] << " Right side arr " <<rightSideArr[i] <<endl; 
    // }

    stack<int> stk;
    int maxArea=0, i=0,top=0;
    while(i<size){
        if(stk.empty() || arr[i]>=arr[stk.top()]){
            stk.push(i++);
        }
        else{
            top = stk.top();
            stk.pop();
            maxArea = max(maxArea, arr[top]*(stk.empty() ? i: i-stk.top() -1
            ));
        }
    }
    while(!stk.empty()){
        top = stk.top();
        stk.pop();
        maxArea = max(maxArea, arr[top]*(stk.empty() ? i: i-stk.top()-1));
    }
    return maxArea;

    // stack<int> s;
  
    // int max_area = 0; // Initialize max area
    // int tp;  // To store top of stack
    // int area_with_top; // To store area with top bar
    //                    // as the smallest bar
  
    // // Run through all bars of given histogram
    // int i = 0;
    // while (i < size)
    // {
    //     // If this bar is higher than the bar on top 
    //     // stack, push it to stack
    //     if (s.empty() || arr[s.top()] <= arr[i])
    //         s.push(i++);
  
    //     // If this bar is lower than top of stack, 
    //     // then calculate area of rectangle with stack 
    //     // top as the smallest (or minimum height) bar. 
    //     // 'i' is 'right index' for the top and element 
    //     // before top in stack is 'left index'
    //     else
    //     {
    //         tp = s.top();  // store the top index
    //         s.pop();  // pop the top
  
    //         // Calculate the area with hist[tp] stack 
    //         // as smallest bar
    //         area_with_top = arr[tp] * (s.empty() ? i : 
    //                                i - s.top() - 1);
  
    //         // update max area, if needed
    //         if (max_area < area_with_top)
    //             max_area = area_with_top;
    //     }
    // }
  
    // // Now pop the remaining bars from stack and calculate
    // // area with every popped bar as the smallest bar
    // while (s.empty() == false)
    // {
    //     tp = s.top();
    //     s.pop();
    //     area_with_top = arr[tp] * (s.empty() ? i : 
    //                             i - s.top() - 1);
  
    //     if (max_area < area_with_top)
    //         max_area = area_with_top;
    // }
  
    // return max_area;
}

int main(){
    int arr[] = {6,2,5,4,5,1,6};
    cout << largestAreaRect(arr, 7) <<endl;
    return 0;
}