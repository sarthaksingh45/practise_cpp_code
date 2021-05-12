#include <iostream>
using namespace std;

bool isPrime(int number){
	
	for(int i=2;i<number; i++){
		if(number%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int p;
    cin >> p;

    if(isPrime(p)){
		cout << "Number is Prime" << endl;
	} 
	else{
		cout << "Number is not Prime";
	}
	
    return 0;
}
	
