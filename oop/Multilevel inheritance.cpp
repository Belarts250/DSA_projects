#include<iostream>
using namespace std;

class A{
	public: void printA(){
		cout  << "Class A" << endl;
	}
};

class B: public A{
	public: void printB(){
		cout  << "Class B";
	}
};

class C: public B{

};
int main(){
	C obj;
	obj.printA();
	obj.printB();
}