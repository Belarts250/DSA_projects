#include <iostream>
using namespace std;
int main(){
	
	int product = 1;
	
	for(int i = 1; i < 20; i++){
		if( i % 2 != 0){
			product *= i;		
		}		
	}
	cout << product;
}