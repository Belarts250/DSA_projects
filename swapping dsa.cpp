#include <iostream>
using namespace std;
void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp; 

}
int main(){
	
	int x = 2, y = 3;
	
	cout << "Before swapping: x = " << x << " and y = " << y << endl;
	swap(x,y);
	cout << "After swapping: x = " << x << " and y = " << y ;
	return 0;
	

	 
	
}