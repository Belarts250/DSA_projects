#include<bits/stdc++.h>
using namespace std;


int main(){
	
	string str;
	cout << "Enter string to reverse: ";
	cin >> str;
	
	stack<char> s;
	
	for(char c: str){
		s.push(c);
	}
	
	string reversedString = "";
	
	while(!s.empty()){
		reversedString += s.top();
		s.pop();
	}
	
	cout << reversedString;
	
}