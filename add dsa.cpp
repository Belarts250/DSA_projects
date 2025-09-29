#include<iostream>
using namespace std;
	
	int add(int num1,int num2){
	cout << "Enter the first number: ";
	cin >> num1;
	cout << "Enter the second number: ";
	cin >> num2;
		int sum = num1 + num2;
		cout << "The sum of " << num1 << " and " << num2 << " is " << sum;
		return sum;
	}
	
int main(){
	add(4,5);
	
	return 0;
}