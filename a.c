#include <iostream>

bool isPrime(int number){
	int i=0;
	for(i=0;i<number; i++){
		if(number%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int p;
	scanf("%d",&p);
	is(isPrime(p)){
		printf("Number is Prime");
	}
	else{
	printf("Number is not prime");
}
return 0;
	}
	
