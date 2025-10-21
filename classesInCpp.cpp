#include<iostream>
using namespace std;

class Car{
	public:
		string color;
		string brand;
	
	void drive(){
		cout << brand << " which is " << color << " is " << " started ";
	}
};

int main(){
	
	Car lamborghini;
	lamborghini.color = "black";
	lamborghini.brand = "lamborghin v1";
	lamborghini.drive();
	
}