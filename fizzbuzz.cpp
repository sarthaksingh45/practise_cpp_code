#include <iostream>
using namespace std;

int main(){
    
    for(int i=0;i<6;i++){
        for(int j=0; j<2; j++){
            for(int k=1; k<=4; k++){
                if(((5*j)+k)%3==0){
                    cout << "Fizz" << endl;
                }
                else{
                    cout << (15*i)+(5*j)+k <<endl;
                }
                
            }
            cout << "Buzz" << endl;
        }
        

        cout << (15*i)+11 << endl;
        cout << "Fizz" <<endl;
        for(int count1 =0; count1 <2; count1++){
            cout<< (15*i) + (count1+ 13) << endl;
        }

        cout << "FizzBuzz" << endl;
    }

    

   
}