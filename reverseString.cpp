#include <iostream>
using namespace std;

string reverseString(string name, int i){
	if (i <0)  return "" ;
	return name[i]+ reverseString(name, i-1);
}


int main(){
	string name = "Sandrine";
	int i = name.length()-1;
	
	cout<<reverseString(name, i);
	
	return 0;
}