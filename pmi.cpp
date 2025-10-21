#include<iostream>
using namespace std;

int recursive(int n){
	if( n == 1){
		return 1;
	} else {
		int recursiveAnswer = n + recursive(n-1);
		return recursiveAnswer;
	}
}

int main(){
	int num = 10;
	int n = 10;
	int pmi;
	for(int i=0;i <= num; i++){
	 pmi = i*(i+1)/2;
	 cout << "The sum of first "<< i << " numbers is "<< pmi << endl;
	 
	}
	
	cout << "The formula of PMI gives " << pmi << endl;
		int Answer = recursive(10);
	cout << "The formula of recursive gives " << Answer << endl;	
		if(pmi == Answer){
			cout << "So, the formula is proven because they are equal";
		}
		else{
			cout << "The formula is incorrect";
		}
	

}