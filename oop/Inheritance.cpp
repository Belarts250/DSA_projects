#include<iostream>
using namespace std;

class Car{
	
	public: 
	
	string object;
	string brand;
	
	virtual void start(){
		cout << "Hello I am a car ???"<< endl;
	}
};

class RwandaCar : public Car {
	public:
	string country;
	
	void start() override{
		cout << "Hi again I'm Lambo??? " << endl;
	}
};

int main(){
	
	RwandaCar car1;
	car1.object = "car" ;
	car1.brand = "Lamborhiniiii";
	car1.country = "Rwanda";
	car1.start();
	
	cout << "I am a " << car1.object << endl;
	cout << "I am a brand of " << car1.brand << endl;
	cout << "I am from " << car1.country << endl;
	
}