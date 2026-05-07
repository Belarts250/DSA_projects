#include<iostream>
#include <cmath>   


using namespace std;


int radius = 5;
int volume;
double pi = 2 * acos(0.0); 

int main(){
	
	volume = (4*pi*radius*radius*radius)/3;
 	cout << "Volume of sphere = " << volume << endl;
		
}