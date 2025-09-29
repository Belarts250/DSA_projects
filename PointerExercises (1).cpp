#include <iostream>
#include <string>
using namespace std;



//************** Question 1 **************

int main() {
   int a, b;
   cout << "Enter two integers: ";
   cin >> a >> b;

   int* ptrA = &a;
   int* ptrB = &b;

   cout << "Value of a using pointer: " << *ptrA << endl;
   cout << "Value of b using pointer: " << *ptrB << endl;

   return 0;
}




// ************** Question 2 **************

void printArray(int *arr, int size){
	int *ptr = arr; 
	cout << "The elements of array are: " << endl;

	for(int i = 0; i< size; i++){
		cout << *(ptr + i);
	}
 cout << endl;
}

int main(){
	int array[5];
	int size = sizeof(array)/sizeof(array[0]);
	
	printArray(array, size);
	
	
	return 0; 
}




// ************** Question 3 **************

void swap(int *num1, int *num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	
	cout << "The numbers after Swap are: " << *num1 << " and " << *num2 <<endl;
}

int main(){
	int num1, num2;
	
	cout << "Enter the first number: ";
	cin >> num1;
	
	cout << "Enter the second number: ";
	cin >> num2;
	
	swap(&num1, &num2);
	
	return 0;
}




// ************** Question 4 **************

struct Point{
	int x;
	int y;
} Coordinate;


int main(){
	struct Point *ptr;
	ptr = &Coordinate;
	
	ptr -> x = 10;
   ptr -> y = 30;
   
   cout << "The values of x and y are: " << Coordinate.x << " and " << Coordinate.y << endl;
   
   return 0;
}




// ************** Question 5 **************

struct Student{
	string name;
	int grade[5];
};


void takestudent(Student *arr, int size){
	
	for(int i= 0; i < size; i++){
		int sum = 0;
		
		for(int j = 0; j < 5; j++){
		 	sum += arr[i].grade[j];
		}
		
		double average = sum / 5.0; 
		
		if(average > 90){
			cout << "Name: " << arr[i].name << ", Average: " << average << endl;
		}

	}
}


int main(){
	struct Student students[3];
	
	students[0] = {"UWASE", {10, 20, 30, 40, 50}};
	students[1] = {"Bubuna", {12, 23, 34, 45, 67}};
	students[2] = {"Ange", {34, 45, 67, 89, 37}};
	
	int size = sizeof(students) / sizeof(students[0]);
	
	takestudent(students, size);
	
	return 0;
}



// ************** Question 6 **************

int* createDynamicArray(int size){
	int* ptr = (int*)malloc(size * sizeof(int));

	for(int i = 0; i < size; i++){
		cin >> ptr[i];
	}
 return ptr;
}

int main(){
	int n;
 cout << "Enter size of array";
	cin >> n;
	int *myArray = createDynamicArray(n);
	
	for(int i = 0; i < n; i++){
		cout << "Element: " << i << " , Value: "<< myArray[i] <<endl;
	}
	cout << endl;
	
	delete[] myArray;
	return 0;
}




// ************** Question 7 **************

struct Product {
   int id;
   double price;
};

int main() {
   Product products[3] = {{1, 12.5}, {2, 45.0}, {3, 99.9}};
   Product* ptrs[3];

   for (int i = 0; i < 3; i++) {
       ptrs[i] = &products[i];
   }

   for (int i = 0; i < 3; i++) {
       cout << "ID: " << ptrs[i]->id << ", Price: " << ptrs[i]->price << endl;
   }
   return 0;
}




// ************** Question 8 **************

struct Contact{
	string name;
	string address;
	string phone_number;
};

void addContact(Contact*& contacts , int& size);
void displayContacts(Contact *contacts, int size);
void searchContact(Contact *contacts, int size , const string& searchName);
void freeMemory(Contact* &contacts);



int main(){
	int size = 0;
	Contact* contacts = nullptr;
	
	int choice;
	do{
		cout << "\n--- Address Book Menu ---\n";
       cout << "1. Add Contact\n";
       cout << "2. Display All Contacts\n";
       cout << "3. Search Contact by Name\n";
       cout << "4. Exit\n";
       cout << "Enter your choice: ";
       cin >> choice;
       
       
       
       cin.ignore();
       
       if(choice == 1){
       	addContact(contacts, size);
		}else if(choice == 2){
			displayContacts(contacts, size);
		}else if(choice == 3){
			string name;
			cout << "Enter name to search: ";
			getline(cin, name);
			searchContact(contacts, size, name);
		}
	}while( choice != 4);
	
	
	freeMemory(contacts);
	cout << "Goodbye!\n";
	return 0;
}



void addContact(Contact*& contacts, int &size){
	Contact* newArray = new Contact[size + 1];
	
	for(int i = 0; i < size; i++){
		newArray[i] = contacts[i];
	}
	
	cout << "Enter name: ";
   getline(cin, newArray[size].name);
   cout << "Enter address: ";
   getline(cin, newArray[size].address);
   cout << "Enter phone number: ";
   getline(cin, newArray[size].phone_number);
   
   
   delete[] contacts;
   contacts = newArray;
   size++;
   
   
   cout << "Contact added successfully!\n";
}



void displayContacts(Contact* contacts, int size){
	if(size == 0){
		cout << "No Contacts available.\n";
		return;
	}
	
	cout << "\n--- Contact List ---\n";
   for (int i = 0; i < size; i++) {
       cout << "Name: " << contacts[i].name << "\n"
            << "Address: " << contacts[i].address << "\n"
            << "Phone: " << contacts[i].phone_number << "\n"
            << "-------------------------\n";
   }
}



void searchContact(Contact* contacts, int size, const string& searchName){
	for(int i = 0; i < size; i++){
		if(contacts[i].name == searchName){
			cout << "\nContact Found:\n";
           cout << "Name: " << contacts[i].name << "\n";
           cout << "Address: " << contacts[i].address << "\n";
           cout << "Phone: " << contacts[i].phone_number << "\n";
           return;
		}
	}
	
	cout << "Contact not found.\n";
}


void freeMemory(Contact*& contacts){
	delete[] contacts;
	contacts = nullptr;
}





// *********** Question 9 ***********

struct Employee {
   int id;
   string name;
   double salary;
};

void displayEmployees(Employee** employees, int size) {
   for (int i = 0; i < size; i++) {
       cout << "ID: " << employees[i]->id
            << ", Name: " << employees[i]->name
            << ", Salary: " << employees[i]->salary
            << endl;
   }
}

int main() {

   Employee employees[5] = {
       {1, "Belise", 3000.50},
       {2, "Sandrine", 2800.75},
       {3, "Prisca", 3500.00},
       {4, "Diana", 4000.20},
       {5, "keza", 2700.10}
   };

   Employee* empPtrs[5];


   for (int i = 0; i < 5; i++) {
       empPtrs[i] = &employees[i];
   }

   displayEmployees(empPtrs, 5);

   return 0;
}




******************* Question 10 *************

int main() {
   char ch = 'Z';     
   char* ptr;       
   char** ptr2;     

   ptr = &ch;        
   ptr2 = &ptr;       

   cout << "Using variable: " << ch << endl;
   cout << "Using *ptr: " << *ptr << endl;
   cout << "Using **ptr2: " << **ptr2 << endl;

   return 0;
}