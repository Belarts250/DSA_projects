#include<iostream>
using namespace std;

int main(){
	string firstName;
	string lastName;
	int age;
	
	cout << "Enter your FirstName : " << endl;
	cin >> firstName;
	cout << "Enter your lastName : " << endl;
	cin >> lastName;
	cout << "Enter your age : " << endl;
	cin >> age;
	
	cout << " Your name is " << firstName  << " " <<  lastName << " you are " << age <<" years old";
}