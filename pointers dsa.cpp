#include <iostream>
using namespace std;


int main(){
	int a;
	int b;
	
	cout << "Enter the first number: ";
	cin >> a;
	
	cout << "Enter the second nuumber: ";
	cin >> b;
		
	int *ptrA = &a;
	int *ptrB = &b;
	
	cout << "The first number is = " << *ptrA << endl;
	cout << "The second number is = " << *ptrB << endl;
	
	
	
	
	
}