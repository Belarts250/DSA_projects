#include<iostream>
using namsespace std;

int main(){
	int capacity  = 5;
	int arr[capacity];
	int n;
	
	cout << "Enter the number of elements" << endl;
	
	cin << n;
	
	cout << "Elements: " << endl;
	
	for(int i= 0; i < n ; i++){
		cin >> arr[i];
	}
	
	int pos, val;
	
	cout << "Enter pos index: ";
	cin >> pos;
	
	cout << "Value: ";
	cin >> val;
	
	if(n >= capacity){
		cout << "Array is full";
	}else if(pos  < 0 || pos>n){
		cout << "Invalid position";
	}else {
		for(int i = n - 1; )
	}
	
}