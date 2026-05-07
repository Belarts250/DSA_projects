#include <iostream>
using namespace std;
struct Product{
	int id;
	double price;
};
int main(){
	
	Product products[3] = {
	{2,4.3},
	{3,5.5},
	{7,8.9}
	};
	
	Product *ptrArray[3];
	
	for(int i = 0; i < 3; i++){
		ptrArray[i] = &products[i];
			cout << "The id of product is = " << ptrArray[i]->id << " ";
			cout << "The price of product is = " << ptrArray[i]->price << endl;
	}

	
}