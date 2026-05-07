#include<iostream>
using namespace std;


int main(){
	
	string fullName;
	int amount;
	int interestrate;
	int time;
	int Total;
	
	cout << "Enter your FullName : " << endl;
	getline(cin, fullName);
	cout << "Enter your Amount : " << endl;
	cin >> amount;
	cout << "Enter your Interest Rate: " << endl;
	cin >> interestrate;
	cout << "Enter the time: ";
	cin >> time;

	Total = (amount*interestrate*time)/100;

	cout << Total;

	
		
}