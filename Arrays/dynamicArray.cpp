#include <iostream>
using namespace std;


int main(){
	int n;
	cout << "Enter the number of elements :";
	cin >> n;
	
	int a[n];
	cout << "The elts are: ";

	for(int i = 0; i<n;i++){
			
			cin >> a[i];
	}
	
	for(int i = 0; i<n;i++){
			
		cout << "Element : " << a[i] << endl;	
	}
	
}

	