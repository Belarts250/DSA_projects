#include <iostream>
using namespace std;
int main(){
	char choice;
	int num1;
	int num2;
	int result;
	char again;
do{
	    cout << "\n=== Simple Calculator ===\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Divide\n";
        cout << "5. Modulo\n";

	cout << "Enter your choice: ";
	cin >> choice;
	
	cout << "Enter your first number: ";
	cin >> num1;
	cout << "Enter your second number: ";
	cin >> num2;
	switch(choice){
		case '1':
			result = num1 + num2;
			cout << "Result: " << result;
			break;
		case '2':
			result = num1 - num2;
			cout << "Result: " << result;
			break;
		case '3':
			result = num1 * num2;
			cout << "Result: " << result;
			break;
		case '4':
			if (num2 != 0){
			result = num1 / num2;
			cout << "Result: " << result;	
			}
			else{
				cout << "Can divide by 0 ";
			}
			break;
		case '5':
			if (num2 != 0){
				result = num1 % num2;
				cout << "Result: " << result;	
			}
			else{
				cout << "Cannot modulo by 0";
			}
		
			break;
			
					 
		default: cout << "Invalid operation ";		
	}	
	
	
    cout << "\n\nDo you want to continue? (y/n): ";
        cin >> again;
        cin.ignore(1000, '\n');

    } 
	while (again == 'y' || again == 'Y');

    cout << "Calculator closed. Goodbye!\n";
	
	
	return 0;
	
}
